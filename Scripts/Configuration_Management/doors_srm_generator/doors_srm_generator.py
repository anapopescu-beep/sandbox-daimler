"""doors_srm_generator.y: Used to extract requirement information from source files/word documents"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "2.1.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Draft'

import pandas as pd
import numpy as np
import os
import sys
import argparse

currentDir = os.getcwd()
sys.path.append(currentDir)

from doors_srm_generator_config import *

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-o', '--output-path', help="pass the output file path", required=True)
    parser.add_argument('-i', '--input-path', help="pass the input folder path", required=True)

    args = parser.parse_args()

    doors_export_path = args.input_path
    doors_export_modules = os.listdir(doors_export_path)

    final_srm = args.output_path

    # Create a Pandas Excel writer using XlsxWriter as the engine.
    writer = pd.ExcelWriter(final_srm, engine='xlsxwriter')

    summary_df = []

    filterLog = open(os.path.join(currentDir, "filter.log"), "w+")
    filterArr = set()

    for i in range(0, len(doors_export_modules)):
        df = []
        temp_summary_df_columns = []
        temp_summary_df_values = []

        data = pd.read_excel(os.path.normpath(os.path.join(doors_export_path, doors_export_modules[i])), keep_default_na=False, na_values=[''])

        df.append(data)

        df = pd.concat(df, sort=False)

        for row, supported_row_values in doors_column_configuration.items():
            if row is not 'ID':
                if row in df:
                    temp_summary_df_columns.append('{} is empty: '.format(row))
                    temp_summary_df_values.append(str(df['ID'].count() - df[row].count()))

            for row_value in supported_row_values:
                if row in df:
                    temp_df = df[df[row].astype('str').str.contains(row_value, regex=True, na=False)]
                    if row is not 'ID':
                        temp_summary_df_columns.append('{} is {}: '.format(row, row_value))
                    else:
                        temp_summary_df_columns.append('Total number of Requierments: ')
                    temp_summary_df_values.append(str(temp_df[row].count()))

        for filter, filter_config in doors_filter_configuration.items():
            temp_df = None
            for j in range(0, len(filter_config['Columns'])):
                if temp_df is None:
                    if filter_config['Columns'][j] in df:
                        if type(filter_config['Values'][j]) == str:
                            if "!" in filter_config['Values'][j]:
                                if filter_config['Values'][j] == "!None":
                                    temp_df_2 = df[filter_config['Columns'][j]].replace(r'^\s*$', np.nan, regex=True)
                                    temp_df = df[~pd.isna(temp_df_2)]
                                else:
                                    temp_df = df[~df[filter_config['Columns'][j]].astype('str').str.contains(filter_config['Values'][j].replace("!", ""), regex=True, na=False)]
                            else:
                                temp_df = df[df[filter_config['Columns'][j]].astype('str').str.contains(filter_config['Values'][j], case=True, regex=True, na=False)]
                        elif type(filter_config['Values'][j]) is list:
                            for item in filter_config['Values'][j]:
                                if temp_df is not None:
                                    temp_df = pd.concat([temp_df, df[df[filter_config['Columns'][j]].astype('str').str.contains(item, regex=True, na=False)]])
                                else:
                                    temp_df = df[df[filter_config['Columns'][j]].astype('str').str.contains(item, regex=True, na=False)]
                        elif filter_config['Values'][j] is None:
                            temp_df = df[pd.isna(df[filter_config['Columns'][j]])]
                else:
                    if filter_config['Columns'][j] in df:
                        if type(filter_config['Values'][j]) == str:
                            if "!" in filter_config['Values'][j]:
                                if filter_config['Values'][j] == "!None":
                                    temp_df_2 = temp_df[filter_config['Columns'][j]].replace(r'^\s*$', np.nan, regex=True)
                                    temp_df = temp_df[~pd.isna(temp_df_2)]
                                else:
                                    temp_df = temp_df[~temp_df[filter_config['Columns'][j]].astype('str').str.contains(filter_config['Values'][j].replace("!", ""), regex=True, na=False)]
                            else:
                                temp_df = temp_df[temp_df[filter_config['Columns'][j]].astype('str').str.contains(filter_config['Values'][j], case=True, regex=True, na=False)]
                        elif type(filter_config['Values'][j]) is list:
                            temp_df_temp = None
                            for item in filter_config['Values'][j]:
                                if temp_df_temp is not None:
                                    temp_df_temp = pd.concat([temp_df_temp, temp_df[temp_df[filter_config['Columns'][j]].astype('str').str.contains(item, regex=True, na=False)]])
                                else:
                                    temp_df_temp = temp_df[temp_df[filter_config['Columns'][j]].astype('str').str.contains(item, regex=True, na=False)]
                            temp_df = temp_df_temp
                        elif filter_config['Values'][j] is None:
                            temp_df = temp_df[pd.isna(temp_df[filter_config['Columns'][j]])]

            row_str = ''
            for j in range(0, len(filter_config['Columns'])):
                if filter_config['Columns'][j] in df:
                    if type(filter_config['Values'][j]) == str:
                        if "!" in filter_config['Values'][j]:
                            row_str += '{} must not be {} '.format(filter_config['Columns'][j], filter_config['Values'][j].replace("!",""))
                        else:
                            row_str += '{} must be {} '.format(filter_config['Columns'][j], filter_config['Values'][j])
                    elif type(filter_config['Values'][j]) == list:
                        row_str += '{} must be {} '.format(filter_config['Columns'][j], ' || '.join(filter_config['Values'][j]))
                    elif filter_config['Values'][j] is None:
                        row_str += '{} must be {} '.format(filter_config['Columns'][j], 'Empty')
                    if j != (len(filter_config['Columns']) - 1):
                        row_str += ' &&'

            filterArr.add('{}: {}\n'.format(filter, row_str))
            temp_summary_df_columns.append(filter)
            temp_summary_df_values.append(str(temp_df['ID'].count()))

        summary_df.append(pd.DataFrame(temp_summary_df_values, index=temp_summary_df_columns, columns=[os.path.splitext(doors_export_modules[i])[0]]).astype('int32'))

        df.to_excel(writer, sheet_name=os.path.splitext(doors_export_modules[i])[0], index=False)

    pd.concat(summary_df, axis=1, sort=False).to_excel(writer, sheet_name='Summary')

    if chart_configuration is not None:
        workbook = writer.book
        worksheet = writer.sheets['Summary']

        for chart_name, chart_config in chart_configuration.items():
            # Create a chart object.
            chart = workbook.add_chart({'type': 'pie'})

            chart.add_series({
                'categories': chart_config['Categories'],
                'values': chart_config['Values'],
                'name': chart_name
            })

            # Insert the chart into the worksheet.
            worksheet.insert_chart(chart_config['Location'], chart)

    # Close the Pandas Excel writer and output the Excel file.
    writer.save()

    for member in filterArr:
        filterLog.write(member)

if __name__ == '__main__':
    main()

import json
import pprint
import ast

def main ():
    json_data = open("AEC_Configurator_Data.json").read()
    data = ast.literal_eval(json_data)
    # pprint.pprint(data)

    componentName = ''
    deskillVal = ''
    validSwitchVal = ''
    componentGroup = 0
    groupSwitch = False
    validSwitch = False
    deskillSwitch = False

    for component in data['aecComponentList']:
        for key, value in component.items():
            if key == 'componentTitle':
                componentName = value
            elif key == 'params':
                for obj in value:
                    for key2, value2 in obj.items():
                        if key2 == 'paramName':
                            for key3, value3 in value2.items():
                                if key3 == 'this':
                                    if value3 == 'Group':
                                        groupSwitch = True
                                        break
                                    if value3 == 'Validation threashold':
                                        validSwitch = True
                                        break
                                    if value3 == 'Deskill threashold':
                                        deskillSwitch = True
                                        break
                        if groupSwitch:
                            if key2 == 'paramValue':
                                for key3, value3 in value2.items():
                                    if key3 == 'this':
                                        componentGroup = value3
                                        groupSwitch = False
                                        break
                        if validSwitch:
                            if key2 == 'paramValue':
                                for key3, value3 in value2.items():
                                    if key3 == 'this':
                                        validSwitchVal = value3
                                        validSwitch = False
                                        break
                        if deskillSwitch:
                            if key2 == 'paramValue':
                                for key3, value3 in value2.items():
                                    if key3 == 'this':
                                        deskillVal = value3
                                        deskillSwitch = False
                                        break

                print('"{}","{}",{},{}'.format(componentName, data['aecGroupTab'][int(componentGroup)]['aecGroupName'], validSwitchVal, deskillVal))
    print('.')

if __name__ == '__main__':
    main()

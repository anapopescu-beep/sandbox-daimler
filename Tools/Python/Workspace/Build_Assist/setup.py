"""Minmal setup file for SWATT Helper"""

from setuptools import setup, find_packages

import sys

setup(
    name='build_assist',
    version = '1.0.1',
    license = 'proprietary',
    description="The assistant for the autoliv build environment",

    author = 'Dan Dan Dustinta',
    author_email = "dan.dustinta@autoliv.com",
    url="",

    packages = find_packages(where='src'),
    package_dir= {'': 'src'},

    install_requires=['pyyaml', 'bincopy', 'fpdf', 'openpyxl', 'image', 'matplotlib', 'argparse', 'pathlib', 'pywin32', 'numpy'],

    include_package_data=True,
    
    extras_require={'pytest': 'pytest-cov'},

    entry_points={
        'console_scripts': [
            'aria_wrapper     = build_assist.cli.aria_wrapper:main',
            'cksum            = build_assist.cli.cksum:main',
            'eclipse_prj_gen  = build_assist.cli.eclipse_prj_gen:main',
            'ptc_cp_wrapper   = build_assist.cli.ptc_cp_wrapper:main',
            'report_gen       = build_assist.cli.report_gen:main',
            'srec_cat_wrapper = build_assist.cli.srec_cat_wrapper:main',
			'generate_nvp_files. = build_assist.cli.generate_nvp_files:main',
			'change_sw_version = build_assist.cli.change_sw_version:main',
            'warning_parser   = build_assist.cli.warning_parser:main',
            'path_cleaner     = build_assist.cli.path_cleaner:main',
            'ptc_issue_report   = build_assist.cli.ptc_issue_report:main',
			'qac_warning_plotter = build_assist.cli.qac_warning_plotter:main'
        ]
    }
)

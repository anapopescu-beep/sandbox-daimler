"""eclipse_prj_gen.py: Used to generate CDT project for Eclipse"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "2.0.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import argparse
import os, sys
from pathlib import Path
from random import randint
import yaml
import glob

currentDir = os.getcwd()
sys.path.append(currentDir)

def random_with_n_digits(n):
    range_start = 10**(n-1)
    range_end = (10**n)-1
    return randint(range_start, range_end)

def define_eclipse_link_file(realFilePath):
    retStr = None

    linkTemplate = """\
        <link>
			<name>{folderStructurePath}/{fileStem}</name>
			<type>1</type>
			<location>{realFilePath}</location>
		</link>"""

    pathParts = Path(realFilePath).parts

    for folder_config_list in eclipse_config['eclipseFolderConfig']:

        if folder_config_list[0]:
            for folder_condition in folder_config_list[0]:

                if folder_condition.replace('\\', '/') + '/' in realFilePath.replace('\\', '/'):

                    tempPathParts = []

                    try:
                        for idx in range(pathParts.index(folder_condition), len(pathParts)-1):
                            tempPathParts.append(pathParts[idx])
                    except:
                        print(',.')
                    retStr = linkTemplate.format(folderStructurePath=folder_config_list[1] + '/' + '/'.join(tempPathParts),
                                                 fileStem=pathParts[len(pathParts) - 1],
                                                 realFilePath=realFilePath)
                    break


        if retStr is not None:
            break
    if retStr is None:
        print('Match not found.')
    return retStr

def define_eclipse_link_dir(realFilePath):
    retStr = ''
    linkTemplate = """\
		<link>
			<name>{folderStem}</name>
			<type>2</type>
			<location>{realFilePath}</location>
		</link>"""

    pathParts = Path(realFilePath).parts

    retStr = linkTemplate.format(folderStem=pathParts[len(pathParts) - 1],
                                 realFilePath=realFilePath)

    return retStr

def define_eclipse_define_opt(defineName, defineValue):
    retStr = ''
    defineTemplate = """\
									<listOptionValue builtIn="false" value="{defineName}={defineValue}"/>
"""

    retStr = defineTemplate.format(defineName=defineName,
                                   defineValue=defineValue)

    return retStr

def define_eclipse_include_file(incPath):
    retStr = ''
    includeTemplate = """\
									<listOptionValue builtIn="false" value="&quot;{incPath}&quot;"/>
"""

    retStr = includeTemplate.format(incPath=incPath)

    return retStr

### Define number and values for unique number id
maxUniqueId = 14
uniqueIdentifiers = ('uniqueCConfigurationId', 'uniqueProjectId', 'uniqueToolchainId', 'uniquePlatformToolchainId', 'uniqueBuilderId', 'uniqueLibrarianId', 'uniqueAssemblyId', 'uniqueInputAssemblyId', 'uniqueGCCppId', 'uniqueInputGCCppId', 'uniqueGCCId', 'uniqueInputGCCId', 'uniqueSymbolsId', 'uniqueIncPathsId')

### Set cproject/project/cdt prefs templates

# {projectName} - templateTestProject
# {linkedResources} - paths to links
projectTemplate = """\
<?xml version="1.0" encoding="UTF-8"?>
<projectDescription>
	<name>{projectName}</name>
	<comment></comment>
	<projects>
	</projects>
	<buildSpec>
		<buildCommand>
			<name>org.eclipse.cdt.managedbuilder.core.genmakebuilder</name>
			<triggers>clean,full,incremental,</triggers>
			<arguments>
			</arguments>
		</buildCommand>
		<buildCommand>
			<name>org.eclipse.cdt.managedbuilder.core.ScannerConfigBuilder</name>
			<triggers>full,incremental,</triggers>
			<arguments>
			</arguments>
		</buildCommand>
	</buildSpec>
	<natures>
		<nature>org.eclipse.cdt.core.cnature</nature>
		<nature>org.eclipse.cdt.managedbuilder.core.managedBuildNature</nature>
		<nature>org.eclipse.cdt.managedbuilder.core.ScannerConfigNature</nature>
	</natures>
    <linkedResources>
{linkedResources}
    </linkedResources>
</projectDescription>
"""

### Set cproject/project/cdt prefs templates

# {projectName} - templateTestProject
# {linkedResources} - paths to links
neevaProjectTemplate = """\
<?xml version="1.0" encoding="UTF-8"?>
<projectDescription>
	<name>{projectName}</name>
	<comment></comment>
	<projects>
	</projects>
	<buildSpec>
		<buildCommand>
			<name>org.eclipse.cdt.managedbuilder.core.genmakebuilder</name>
			<triggers>full,incremental,</triggers>
			<arguments>
			</arguments>
		</buildCommand>
		<buildCommand>
			<name>org.eclipse.cdt.managedbuilder.core.ScannerConfigBuilder</name>
			<triggers>full,incremental,</triggers>
			<arguments>
			</arguments>
		</buildCommand>
	</buildSpec>
	<natures>
		<nature>org.eclipse.cdt.core.cnature</nature>
		<nature>org.eclipse.cdt.managedbuilder.core.managedBuildNature</nature>
		<nature>org.eclipse.cdt.managedbuilder.core.ScannerConfigNature</nature>
	</natures>
    <linkedResources>
{linkedResources}
    </linkedResources>
</projectDescription>
"""

# {projectName} - templateTestProject
# {makeSupportPath} - path to cygwin
# {configurationName} - fbl
# {uniqueCConfigurationId} - 518022405
# {uniqueProjectId} - 1036165277
# {uniqueToolchainId} - 437199136
# {uniquePlatformToolchainId} - 44638694
# {uniqueBuilderId} - 805016398
# {uniqueLibrarianId} - 1755951006
# {uniqueAssemblyId} - 1454202414
# {uniqueInputAssemblyId} - 1228586376
# {uniqueGCCppId} - 1089236271
# {uniqueInputGCCppId} - 730047337
# {uniqueGCCId} - 1111539303
# {uniqueInputGCCId} - 930324428
# {defineResources}
# {includeResources}
cprojectTemplate = """\
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<?fileVersion 4.0.0?><cproject storage_type_id="org.eclipse.cdt.core.XmlProjectDescriptionStorage">
	<storageModule moduleId="org.eclipse.cdt.core.settings">
		<cconfiguration id="0.{uniqueCConfigurationId}">
			<storageModule buildSystemId="org.eclipse.cdt.managedbuilder.core.configurationDataProvider" id="0.{uniqueCConfigurationId}" moduleId="org.eclipse.cdt.core.settings" name="{configurationName}">
				<externalSettings/>
				<extensions>
					<extension id="org.eclipse.cdt.core.GASErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GmakeErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GLDErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.VCErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.CWDLocator" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GCCErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
				</extensions>
			</storageModule>
			<storageModule moduleId="cdtBuildSystem" version="4.0.0">
				<configuration buildProperties="" description="" id="0.{uniqueCConfigurationId}" name="{configurationName}" parent="org.eclipse.cdt.build.core.prefbase.cfg">
					<folderInfo id="0.{uniqueCConfigurationId}." name="/" resourcePath="">
						<toolChain id="org.eclipse.cdt.build.core.prefbase.toolchain.{uniqueToolchainId}" name="No ToolChain" resourceTypeBasedDiscovery="false" superClass="org.eclipse.cdt.build.core.prefbase.toolchain">
							<targetPlatform id="org.eclipse.cdt.build.core.prefbase.toolchain.{uniqueToolchainId}.{uniquePlatformToolchainId}" name=""/>
							<builder buildPath="${{BUILD_PATH}}" cleanBuildTarget="${{ConfigName}}
							" incrementalBuildTarget="${{ConfigName}}" parallelBuildOn="true" parallelizationNumber="unlimited" id="org.eclipse.cdt.build.core.settings.default.builder.{uniqueBuilderId}" keepEnvironmentInBuildfile="false" managedBuildOn="false" name="Gnu Make Builder" superClass="org.eclipse.cdt.build.core.settings.default.builder"/>
							<tool id="org.eclipse.cdt.build.core.settings.holder.libs.{uniqueLibrarianId}" name="holder for library settings" superClass="org.eclipse.cdt.build.core.settings.holder.libs"/>
							<tool id="org.eclipse.cdt.build.core.settings.holder.{uniqueAssemblyId}" name="Assembly" superClass="org.eclipse.cdt.build.core.settings.holder">
								<inputType id="org.eclipse.cdt.build.core.settings.holder.inType.{uniqueInputAssemblyId}" languageId="org.eclipse.cdt.core.assembly" languageName="Assembly" sourceContentType="org.eclipse.cdt.core.asmSource" superClass="org.eclipse.cdt.build.core.settings.holder.inType"/>
							</tool>
							<tool id="org.eclipse.cdt.build.core.settings.holder.{uniqueGCCppId}" name="GNU C++" superClass="org.eclipse.cdt.build.core.settings.holder">
								<inputType id="org.eclipse.cdt.build.core.settings.holder.inType.{uniqueInputGCCppId}" languageId="org.eclipse.cdt.core.g++" languageName="GNU C++" sourceContentType="org.eclipse.cdt.core.cxxSource,org.eclipse.cdt.core.cxxHeader" superClass="org.eclipse.cdt.build.core.settings.holder.inType"/>
							</tool>
							<tool id="org.eclipse.cdt.build.core.settings.holder.{uniqueGCCId}" name="GNU C" superClass="org.eclipse.cdt.build.core.settings.holder">
{defineResources}
{includeResources}
								<inputType id="org.eclipse.cdt.build.core.settings.holder.inType.{uniqueInputGCCId}" languageId="org.eclipse.cdt.core.gcc" languageName="GNU C" sourceContentType="org.eclipse.cdt.core.cSource,org.eclipse.cdt.core.cHeader" superClass="org.eclipse.cdt.build.core.settings.holder.inType"/>
							</tool>
						</toolChain>
					</folderInfo>
				</configuration>
			</storageModule>
			<storageModule moduleId="org.eclipse.cdt.core.externalSettings"/>
		</cconfiguration>
	</storageModule>
	<storageModule moduleId="cdtBuildSystem" version="4.0.0">
		<project id="{projectName}.null.{uniqueProjectId}" name="{projectName}"/>
	</storageModule>
	<storageModule moduleId="scannerConfiguration">
		<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
		<scannerConfigBuildInfo instanceId="0.{uniqueCConfigurationId}">
			<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
		</scannerConfigBuildInfo>
	</storageModule>
    <storageModule moduleId="org.eclipse.cdt.make.core.buildtargets">
		<buildTargets>
			<target name="{configurationName}" path="" targetID="org.eclipse.cdt.build.MakeTargetBuilder">
				<buildCommand>make</buildCommand>
				<buildArguments>-j</buildArguments>
				<buildTarget>{configurationName}</buildTarget>
				<stopOnError>true</stopOnError>
				<useDefaultCommand>true</useDefaultCommand>
				<runAllBuilders>true</runAllBuilders>
			</target>
			<target name="all" path="" targetID="org.eclipse.cdt.build.MakeTargetBuilder">
				<buildCommand>make</buildCommand>
				<buildArguments>-j</buildArguments>
				<buildTarget>all</buildTarget>
				<stopOnError>true</stopOnError>
				<useDefaultCommand>true</useDefaultCommand>
				<runAllBuilders>true</runAllBuilders>
			</target>
			<target name="{configurationName}-clean" path="" targetID="org.eclipse.cdt.build.MakeTargetBuilder">
				<buildCommand>make</buildCommand>
				<buildArguments>-j</buildArguments>
				<buildTarget>{configurationName}-clean</buildTarget>
				<stopOnError>true</stopOnError>
				<useDefaultCommand>true</useDefaultCommand>
				<runAllBuilders>true</runAllBuilders>
			</target>
			<target name="all-release" path="" targetID="org.eclipse.cdt.build.MakeTargetBuilder">
				<buildCommand>make</buildCommand>
				<buildArguments>-j</buildArguments>
				<buildTarget>all-release</buildTarget>
				<stopOnError>true</stopOnError>
				<useDefaultCommand>true</useDefaultCommand>
				<runAllBuilders>true</runAllBuilders>
			</target>
			<target name="{configurationName}-sanity_checks FILTER=" path="" targetID="org.eclipse.cdt.build.MakeTargetBuilder">
				<buildCommand>make</buildCommand>
				<buildArguments>-j</buildArguments>
				<buildTarget>{configurationName}-sanity_checks FILTER=</buildTarget>
				<stopOnError>true</stopOnError>
				<useDefaultCommand>true</useDefaultCommand>
				<runAllBuilders>true</runAllBuilders>
			</target>
            <target name="{configurationName}-neeva_ws" path="" targetID="org.eclipse.cdt.build.MakeTargetBuilder">
				<buildCommand>make</buildCommand>
				<buildArguments>-j</buildArguments>
				<buildTarget>{configurationName}-neeva_ws</buildTarget>
				<stopOnError>true</stopOnError>
				<useDefaultCommand>true</useDefaultCommand>
				<runAllBuilders>true</runAllBuilders>
			</target>
		</buildTargets>
	</storageModule>
	<storageModule moduleId="org.eclipse.cdt.core.LanguageSettingsProviders"/>
</cproject>
"""

neevaCprojectTemplate = """\
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<?fileVersion 4.0.0?><cproject storage_type_id="org.eclipse.cdt.core.XmlProjectDescriptionStorage">
	<storageModule moduleId="org.eclipse.cdt.core.settings">
		<cconfiguration id="0.{uniqueCConfigurationId}">
			<storageModule buildSystemId="org.eclipse.cdt.managedbuilder.core.configurationDataProvider" id="0.{uniqueCConfigurationId}" moduleId="org.eclipse.cdt.core.settings" name="{configurationName}">
				<externalSettings/>
				<extensions>
					<extension id="org.eclipse.cdt.core.GASErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GmakeErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GLDErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.VCErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.CWDLocator" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GCCErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
				</extensions>
			</storageModule>
			<storageModule moduleId="cdtBuildSystem" version="4.0.0">
				<configuration buildProperties="" description="" id="0.{uniqueCConfigurationId}" name="{configurationName}" parent="org.eclipse.cdt.build.core.prefbase.cfg">
					<folderInfo id="0.{uniqueCConfigurationId}." name="/" resourcePath="">
						<toolChain id="org.eclipse.cdt.build.core.prefbase.toolchain.{uniqueToolchainId}" name="No ToolChain" resourceTypeBasedDiscovery="false" superClass="org.eclipse.cdt.build.core.prefbase.toolchain">
							<targetPlatform id="org.eclipse.cdt.build.core.prefbase.toolchain.{uniqueToolchainId}.{uniquePlatformToolchainId}" name=""/>
							<builder buildPath="${{ARIA_COMPILER_WS_PATH}}" cleanBuildTarget="" command="${{ARIA_COMPILER_PATH}}" incrementalBuildTarget=""  enableCleanBuild="false" id="org.eclipse.cdt.build.core.settings.default.builder.{uniqueBuilderId}" keepEnvironmentInBuildfile="false" managedBuildOn="false" name="Gnu Make Builder" superClass="org.eclipse.cdt.build.core.settings.default.builder"/>
							<tool id="org.eclipse.cdt.build.core.settings.holder.libs.{uniqueLibrarianId}" name="holder for library settings" superClass="org.eclipse.cdt.build.core.settings.holder.libs"/>
							<tool id="org.eclipse.cdt.build.core.settings.holder.{uniqueAssemblyId}" name="Assembly" superClass="org.eclipse.cdt.build.core.settings.holder">
								<inputType id="org.eclipse.cdt.build.core.settings.holder.inType.{uniqueInputAssemblyId}" languageId="org.eclipse.cdt.core.assembly" languageName="Assembly" sourceContentType="org.eclipse.cdt.core.asmSource" superClass="org.eclipse.cdt.build.core.settings.holder.inType"/>
							</tool>
							<tool id="org.eclipse.cdt.build.core.settings.holder.{uniqueGCCppId}" name="GNU C++" superClass="org.eclipse.cdt.build.core.settings.holder">
								<inputType id="org.eclipse.cdt.build.core.settings.holder.inType.{uniqueInputGCCppId}" languageId="org.eclipse.cdt.core.g++" languageName="GNU C++" sourceContentType="org.eclipse.cdt.core.cxxSource,org.eclipse.cdt.core.cxxHeader" superClass="org.eclipse.cdt.build.core.settings.holder.inType"/>
							</tool>
							<tool id="org.eclipse.cdt.build.core.settings.holder.{uniqueGCCId}" name="GNU C" superClass="org.eclipse.cdt.build.core.settings.holder">
								<inputType id="org.eclipse.cdt.build.core.settings.holder.inType.{uniqueInputGCCId}" languageId="org.eclipse.cdt.core.gcc" languageName="GNU C" sourceContentType="org.eclipse.cdt.core.cSource,org.eclipse.cdt.core.cHeader" superClass="org.eclipse.cdt.build.core.settings.holder.inType"/>
							</tool>
						</toolChain>
					</folderInfo>
				</configuration>
			</storageModule>
			<storageModule moduleId="org.eclipse.cdt.core.externalSettings"/>
		</cconfiguration>
	</storageModule>
	<storageModule moduleId="cdtBuildSystem" version="4.0.0">
		<project id="{projectName}.null.{uniqueProjectId}" name="{projectName}"/>
	</storageModule>
	<storageModule moduleId="scannerConfiguration">
		<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
		<scannerConfigBuildInfo instanceId="0.{uniqueCConfigurationId}">
			<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
		</scannerConfigBuildInfo>
	</storageModule>
    <storageModule moduleId="org.eclipse.cdt.make.core.buildtargets">
{neeva_targets}
	</storageModule>
	<storageModule moduleId="org.eclipse.cdt.core.LanguageSettingsProviders"/>
</cproject>
"""

neevaTargetTemplate = """\
		<buildTargets>
			<target name="{configurationName}" path="{configurationPath}" targetID="org.eclipse.cdt.build.MakeTargetBuilder">
				<buildCommand>make</buildCommand>
				<buildArguments>-j</buildArguments>
				<buildTarget>{configurationTarget}</buildTarget>
				<stopOnError>true</stopOnError>
				<useDefaultCommand>true</useDefaultCommand>
				<runAllBuilders>true</runAllBuilders>
			</target>
		</buildTargets>
"""

# {makeSupportPath}
# {uniqueCConfigurationId}
cdtTemplate = """\
eclipse.preferences.version=1
environment/project/0.{uniqueCConfigurationId}/GENY_COMPONENTS_PATH/delimiter=;
environment/project/0.{uniqueCConfigurationId}/GENY_COMPONENTS_PATH/operation=replace
environment/project/0.{uniqueCConfigurationId}/GENY_COMPONENTS_PATH/value={genyComponentsPath}
environment/project/0.{uniqueCConfigurationId}/GENY_GNY_PATH/delimiter=;
environment/project/0.{uniqueCConfigurationId}/GENY_GNY_PATH/operation=replace
environment/project/0.{uniqueCConfigurationId}/GENY_GNY_PATH/value={genyGnyPath}
environment/project/0.{uniqueCConfigurationId}/PATH/delimiter=;
environment/project/0.{uniqueCConfigurationId}/PATH/operation=replace
environment/project/0.{uniqueCConfigurationId}/PATH/value=${{CYGWIN_DIR}}\\\\bin;${{COMPILER_DIR}};${{PYTHON_INSTALLATION_DIR}};${{PYTHON_INSTALLATION_DIR}}\\\\Scripts;${{Path}}
environment/project/0.{uniqueCConfigurationId}/append=true
environment/project/0.{uniqueCConfigurationId}/appendContributed=false
environment/project/0.{uniqueCConfigurationId}/FLEXLM_TIMEOUT/delimiter=;
environment/project/0.{uniqueCConfigurationId}/FLEXLM_TIMEOUT/operation=replace
environment/project/0.{uniqueCConfigurationId}/FLEXLM_TIMEOUT/value=1000000
"""

# {makeSupportPath}
# {uniqueCConfigurationId}
neevaCdtTemplate = """\
eclipse.preferences.version=1
environment/project/0.{uniqueCConfigurationId}/ARIA_PATH/delimiter=;
environment/project/0.{uniqueCConfigurationId}/ARIA_PATH/operation=replace
environment/project/0.{uniqueCConfigurationId}/ARIA_PATH/value={ariaPath}
environment/project/0.{uniqueCConfigurationId}/ARIA_COMPILER_PATH/delimiter=;
environment/project/0.{uniqueCConfigurationId}/ARIA_COMPILER_PATH/operation=replace
environment/project/0.{uniqueCConfigurationId}/ARIA_COMPILER_PATH/value={ariaCompilerPath}
environment/project/0.{uniqueCConfigurationId}/ARIA_COMPILER_WS_PATH/delimiter=;
environment/project/0.{uniqueCConfigurationId}/ARIA_COMPILER_WS_PATH/operation=replace
environment/project/0.{uniqueCConfigurationId}/ARIA_COMPILER_WS_PATH/value={ariaCompilerWsPath}
"""

makefileTextPreferences = """\
content-types/org.eclipse.cdt.make.core.makefile/file-patterns=Makefile.*
eclipse.preferences.version=1
"""

parser = argparse.ArgumentParser()
parser.add_argument('-p', '--project-name', help="Set the Eclipse project name", required=True)
parser.add_argument('-b', '--build-config', help="Set the active build configuration", required=True)
parser.add_argument('-w', '--project-path', help="Set the Eclipse project output path", required=True)
parser.add_argument('-c', '--config-path', help="Set the config file path", required=True)
parser.add_argument('-n', '--neeva_switch', help="Environment switch to generate NEEVA workspace", type=bool, default=False)

args = parser.parse_args()

fin = open("eclipse_config.yaml", "rt")
fout = open("eclipse_config_processed.yaml", "wt")
for line in fin:
    fout.write(line.replace('  ', ' '))
fin.close()
fout.close()

with open("eclipse_config_processed.yaml", 'r') as stream:
    try:
        eclipse_config = yaml.load(stream, Loader=yaml.FullLoader)
    except yaml.YAMLError as exc:
        print(exc)

def main():
    if args.neeva_switch == True:
        generate_neeva_ws()
    else:
        generate_c_ws()

    os.remove("eclipse_config_processed.yaml")

def generate_c_ws(cdtTemplate=cdtTemplate):
    ### Init Defines/Symbol lists
    definesListStr = """								<option id="org.eclipse.cdt.build.core.settings.holder.symbols.792164604" name="Symbols" superClass="org.eclipse.cdt.build.core.settings.holder.symbols" valueType="definedSymbols">\n"""
    incListStr = """								<option id="org.eclipse.cdt.build.core.settings.holder.incpaths.{uniqueIncPathsId}" superClass="org.eclipse.cdt.build.core.settings.holder.incpaths" valueType="includePath">\n"""

    randomNumberList = []
    cProjectUniqueDict = {}
    projectUniqueDict = {}
    cdtUniqueDict = {}

    cProjectUniqueDict['projectName'] = args.project_name
    projectUniqueDict['projectName'] = args.project_name
    cProjectUniqueDict['configurationName'] = args.build_config

    if not os.path.isdir(args.project_path):
        os.makedirs(args.project_path, exist_ok=True)

    linkedFileListStr = ''


    for linkFile in eclipse_config['linkFiles']:
        if linkFile is None:
            print('.')
        try:
            linkedFileListStr += define_eclipse_link_file(linkFile)
        except Exception as e:
            print(e)

    for linkDir in eclipse_config['linkDirs']:
        linkedFileListStr += define_eclipse_link_dir(linkDir)

    for defineName in eclipse_config['systemDefines']:
        if '=' in defineName:
            defineName = defineName.split('=')
            definesListStr += define_eclipse_define_opt(defineName[0], defineName[1])
        else:
            definesListStr += define_eclipse_define_opt(defineName, '')
    definesListStr += """								</option>"""

    for incPath in eclipse_config['incPathList']:
        incListStr += define_eclipse_include_file(incPath)
    incListStr += """								</option>"""

    for i in range(0, maxUniqueId):
        randomNumberList.append(random_with_n_digits(10))
        cProjectUniqueDict[uniqueIdentifiers[i]] = randomNumberList[i]

    cProjectUniqueDict['defineResources'] = definesListStr
    cProjectUniqueDict['includeResources'] = incListStr

    projectUniqueDict['linkedResources'] = linkedFileListStr

    cdtUniqueDict['genyComponentsPath'] = eclipse_config['genyComponentsPath']
    cdtUniqueDict['genyGnyPath'] = eclipse_config['genyGnyPath']
    cdtUniqueDict['uniqueCConfigurationId'] = cProjectUniqueDict['uniqueCConfigurationId']

    if not os.path.isdir(os.path.normpath(os.path.join(args.project_path, '.settings'))):
        os.makedirs(os.path.normpath(os.path.join(args.project_path, '.settings')), exist_ok=True)

    ### Write output files
    fileCProject = open(os.path.normpath(os.path.join(args.project_path, '.cproject')), 'w+')
    fileProject = open(os.path.normpath(os.path.join(args.project_path, '.project')), 'w+')

    fileCdtPres = open(os.path.normpath(os.path.join(args.project_path, '.settings', 'org.eclipse.cdt.core.prefs')), 'w+')
    fileCProject.write(cprojectTemplate.format(**cProjectUniqueDict))
    fileProject.write(projectTemplate.format(**projectUniqueDict))

    if os.path.isfile(os.path.join(args.config_path, 'env_variables.yaml')):
        with open(os.path.join(args.config_path, 'env_variables.yaml'), 'r') as stream:
            try:
                env_var_config = yaml.load(stream, Loader=yaml.FullLoader)
            except yaml.YAMLError as exc:
                print(exc)

        for env_var, env_var_value in env_var_config.items():
            cdtTemplate += '''\n\
environment/project/0.{{uniqueCConfigurationId}}/{0}/delimiter=;
environment/project/0.{{uniqueCConfigurationId}}/{0}/operation=replace
environment/project/0.{{uniqueCConfigurationId}}/{0}/value={1}'''.format(env_var, os.path.normpath(env_var_value).replace('\\', '/'))

        fileCdtPres.write(cdtTemplate.format(**cdtUniqueDict))
    else:
        fileCdtPres.write(cdtTemplate.format(**cdtUniqueDict))

    fileCProject.close()
    fileProject.close()
    fileCdtPres.close()

    if not os.path.isdir(os.path.normpath(os.path.join(args.project_path, '..', '..', 'eclipse_workspace', '.metadata', '.plugins', 'org.eclipse.core.runtime', '.settings'))):
        os.makedirs(os.path.normpath(os.path.join(args.project_path, '..', '..', 'eclipse_workspace', '.metadata', '.plugins', 'org.eclipse.core.runtime', '.settings')), exist_ok=True)

    eclipseMakePreferences = open(os.path.normpath(os.path.join(args.project_path, '..', '..', 'eclipse_workspace', '.metadata', '.plugins', 'org.eclipse.core.runtime', '.settings', 'org.eclipse.core.runtime.prefs')), 'w+')
    eclipseMakePreferences.write(makefileTextPreferences)
    eclipseMakePreferences.close()


def generate_neeva_ws():
    randomNumberList = []
    cProjectUniqueDict = {}
    projectUniqueDict = {}
    cdtUniqueDict = {}
    linkedFileListStr = ''



    for linkDir in eclipse_config['linkDirs']:
        linkedFileListStr += define_eclipse_link_dir(linkDir)

        pathParts = Path(linkDir).parts

        if 'neeva_targets' not in cProjectUniqueDict:
                cProjectUniqueDict['neeva_targets'] = ""

        for filename in glob.iglob(os.path.join(linkDir, '**', '*.ts'), recursive=True):
            pathPartsTarget = Path(filename).parts
            for idx in range(0,len(pathParts)):
                if pathParts[idx] == pathPartsTarget[idx]:
                    jdx = idx

            cProjectUniqueDict['neeva_targets'] += neevaTargetTemplate.format(configurationName='{}'.format(os.path.basename(filename)),
                                                                              configurationPath="",
                                                                              configurationTarget='-s={}'.format(os.path.normpath(filename)))

            #os.path.join(*pathPartsTarget[jdx:-1])

    cProjectUniqueDict['projectName'] = args.project_name
    projectUniqueDict['projectName'] = args.project_name
    cProjectUniqueDict['configurationName'] = args.build_config

    if not os.path.isdir(args.project_path):
        os.makedirs(args.project_path, exist_ok=True)

    for i in range(0, maxUniqueId):
        randomNumberList.append(random_with_n_digits(10))
        cProjectUniqueDict[uniqueIdentifiers[i]] = randomNumberList[i]

    projectUniqueDict['linkedResources'] = linkedFileListStr

    cdtUniqueDict['ariaCompilerPath'] = eclipse_config['ariaCompilerPath']
    cdtUniqueDict['ariaCompilerWsPath'] = eclipse_config['ariaCompilerWsPath']
    cdtUniqueDict['ariaPath'] = eclipse_config['ariaPath']
    cdtUniqueDict['uniqueCConfigurationId'] = cProjectUniqueDict['uniqueCConfigurationId']

    if not os.path.isdir(os.path.normpath(os.path.join(args.project_path, '.settings'))):
        os.makedirs(os.path.normpath(os.path.join(args.project_path, '.settings')), exist_ok=True)

    ### Write output files
    fileCProject = open(os.path.normpath(os.path.join(args.project_path, '.cproject')), 'w+')
    fileProject = open(os.path.normpath(os.path.join(args.project_path, '.project')), 'w+')
    fileCdtPres = open(os.path.normpath(os.path.join(args.project_path, '.settings', 'org.eclipse.cdt.core.prefs')), 'w+')

    fileCProject.write(neevaCprojectTemplate.format(**cProjectUniqueDict))
    fileProject.write(neevaProjectTemplate.format(**projectUniqueDict))
    fileCdtPres.write(neevaCdtTemplate.format(**cdtUniqueDict))

    fileCProject.close()
    fileProject.close()

if __name__ == '__main__':
    main()

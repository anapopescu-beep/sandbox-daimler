DD_Root_Scalings = 'Pool/Scalings';
DD_Root_Variables = ['Pool/Variables/' 'RTE_DEFINES'];
dsdd('Create','RTE_DEFINES','Parent','/Pool/Variables','objectKind','VariableGroup');

DD_Root_Autosar_DataMappings = ['Pool/Autosar/DataTypeMappingSets'];
DD_Root_Autosar_ApplicationDataTypes = ['/Pool/Autosar/ApplicationDataTypes'];
DD_Root_Autosar_ImplementationDataTypes = ['/Pool/Typedefs'];

% List all DataTypeMappings 
hDataMappings = dsdd('Find',DD_Root_Autosar_DataMappings,'objectkind','DataTypeMap');

disp('*** Referencing scalings in implementation data types and Scaling importation START :');

for i=1:length(hDataMappings),
    
    % Get DataMapping path in DD as well as corresponding Application type
    % and implementation types references
    hDataMappingPath{i} = dsdd('GetAttribute',hDataMappings(i),'Path');
    hAppDataTypesRefs{i} = dsdd('Get',hDataMappingPath{i},'ApplicationDataTypeRef');
    hImplDataTypesRefs{i} = dsdd('Get',hDataMappingPath{i},'TypedefRef');
    
    % Retrieve scaling ref associated to application data type, and names
    % of implementation and application data types
    hAppTypeScalingRef = dsdd('Get',[DD_Root_Autosar_ApplicationDataTypes,'/',hAppDataTypesRefs{i}],'ScalingRef');
    hAppTypeName = dsdd('GetAttribute',[DD_Root_Autosar_ApplicationDataTypes,'/',hAppDataTypesRefs{i}],'Name');
    hImpTypeName = dsdd('GetAttribute',[DD_Root_Autosar_ImplementationDataTypes,'/',hImplDataTypesRefs{i}],'Name');
    
    % If no scaling is referenced by the application data type
    if (0 == length(hAppTypeScalingRef)),
        disp( ['*** AppDataType ',hAppTypeName,' does not reference scaling']);
    else    
        % Reference this scaling in corresponding implementation data type
        dsdd('CreateConstraints',[DD_Root_Autosar_ImplementationDataTypes,'/',hImplDataTypesRefs{i}]);
        dsdd('Set',[DD_Root_Autosar_ImplementationDataTypes,'/',hImplDataTypesRefs{i},'/Constraints'],'ScalingRef',hAppTypeScalingRef);
        disp( ['*** AppDataType ',hAppTypeName,'Scaling referenced in corresponding impDataType ',hImpTypeName]);
        
        % Retrieve scaling name and type
        hScalingName = dsdd('GetAttribute',[DD_Root_Scalings,'/',hAppTypeScalingRef],'Name');
        type = dsdd('Get',[DD_Root_Scalings,'/',hAppTypeScalingRef],'ConversionType');
        
        % If the scaling is an ENUM, create variables for each enum element
        if strcmp(type,'TAB_VERB')
             EnumList = dsdd('Get',[DD_Root_Scalings,'/',hAppTypeScalingRef],'ConversionStrings');
             EnumValues = dsdd('Get',[DD_Root_Scalings,'/',hAppTypeScalingRef],'ConversionTable');
             ScalingType = dsdd('Get',[DD_Root_Autosar_ImplementationDataTypes,'/',hImplDataTypesRefs{i}],'BaseType');
             if (0 == length(ScalingType)),
                 ScalingType = 'UInt8'
             end
             
            for j=1:numel(EnumList)
              dsdd('Create',EnumList{j},'Parent',DD_Root_Variables,'objectKind','Variable');
              dsdd('Set',[DD_Root_Variables,'/',EnumList{j}],'Type',ScalingType,'Class','AUTOSAR/RTE/RTE_DEFINE','Value',EnumValues(j));
              disp( ['*** Scaling : ',hScalingName, ' - Element added : ',EnumList{j}]);
            end
        else
            disp( ['*** Scaling ',hScalingName,' is not an ENUM']);
        end
    end
    disp( ['*** ----------------------------------------------------------------------------------------------------']);
end
disp('*** Referencing scalings in implementation data types and Scaling importation FINISHED');
disp('***===================================================================================');
disp('*** Creating variables for BSW related computation methods')
disp('***===================================================================================');

hBSWImpTypeTable = {'/Pool/Typedefs/AUTOSAR_Dem','/Pool/Typedefs/AUTOSAR_NvM'};

for i=1:length(hBSWImpTypeTable)
    % List all BSW implementation data types 
    hBSWImpTypes = dsdd('Find',hBSWImpTypeTable{i},'objectkind','Typedef');
      
    for j=1:length(hBSWImpTypes)
        hBSWImpTypesPath{j} = dsdd('GetAttribute',hBSWImpTypes(j),'Path');
        hBSWImpTypeScalingRef = dsdd('Get',[hBSWImpTypesPath{j},'/Constraints'],'ScalingRef');
        
        hScalingName = dsdd('GetAttribute',[DD_Root_Scalings,'/',hBSWImpTypeScalingRef],'Name');
        type = dsdd('Get',[DD_Root_Scalings,'/',hBSWImpTypeScalingRef],'ConversionType');
        
        % If the scaling is an ENUM, create variables for each enum element
        if strcmp(type,'TAB_VERB')
             EnumListBSW = dsdd('Get',[DD_Root_Scalings,'/',hBSWImpTypeScalingRef],'ConversionStrings');
             EnumValuesBSW = dsdd('Get',[DD_Root_Scalings,'/',hBSWImpTypeScalingRef],'ConversionTable');
             ScalingType = dsdd('Get',[DD_Root_Autosar_ImplementationDataTypes,'/',hImplDataTypesRefs{i}],'BaseType');
             if (0 == length(ScalingType)),
                 ScalingType = 'UInt8'
             end
             
            for k=1:numel(EnumListBSW)
              dsdd('Create',EnumListBSW{k},'Parent',DD_Root_Variables,'objectKind','Variable');
              dsdd('Set',[DD_Root_Variables,'/',EnumListBSW{k}],'Type',ScalingType,'Class','AUTOSAR/RTE/RTE_DEFINE','Value',EnumValuesBSW(k));
              disp( ['*** Scaling : ',hScalingName, ' - Element added : ',EnumListBSW{k}]);
            end
        else
            disp( ['*** Scaling ',hScalingName,' is not an ENUM']);
        end
    end
end






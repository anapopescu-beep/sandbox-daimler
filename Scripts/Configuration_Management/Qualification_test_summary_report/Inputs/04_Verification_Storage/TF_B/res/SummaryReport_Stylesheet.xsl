<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xlink="http://www.w3.org/1999/xlink">

	<xsl:template name="break">
		<xsl:param name="text" select="."/>
		<xsl:choose>
			<xsl:when test="contains($text, '&#xa;')">
				<xsl:value-of select="substring-before($text, '&#xa;')"/>
				<br/>
				<xsl:call-template name="break">
					<xsl:with-param name="text" select="substring-after($text, '&#xa;')"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$text"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template name="break_2">
		<xsl:param name="text" select="."/>
		<xsl:choose>
			<xsl:when test="contains($text, '&#xa;')">
				<xsl:choose>
					<xsl:when test="contains(substring-before($text, '&#xa;'),'PASSED')">
						<font color="#339933">
							<xsl:value-of select="substring-before($text, '&#xa;')"/>
						</font>
					</xsl:when>
					<xsl:when test="contains(substring-before($text, '&#xa;'),'FAILED')">
						<font color="#FF0000">
							<xsl:value-of select="substring-before($text, '&#xa;')"/>
						</font>
					</xsl:when>
					<xsl:when test="contains(substring-before($text, '&#xa;'),'TOBEANALYZED')">
						<font color="#F7D838">
							<xsl:value-of select="substring-before($text, '&#xa;')"/>
						</font>
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="substring-before($text, '&#xa;')"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$text"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template name="test_name">
		<xsl:param name="text" select="."/>
		<xsl:choose>
			<xsl:when test="contains($text, 'Test case ID:')">
				<xsl:call-template name="break_2">
					<xsl:with-param name="text" select="substring-after($text, 'Test case ID:')"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise> </xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template name="test_result">
		<xsl:param name="text" select="."/>
		<xsl:choose>
			<xsl:when test="contains($text, 'Result Test:')">
				<xsl:call-template name="break_2">
					<xsl:with-param name="text" select="substring-after($text, 'Result Test:')"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise> </xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template match="/">
		<html>
			<head>
				<script type="text/javascript">
				<![CDATA[
				function ShowRequirements() 
				{
				 var trList = document.getElementsByTagName("table");
				 box = eval("document.SROptions.C1"); 
					if(box.checked == true)
					{
						for(a=0;a<trList.length;a++)
						 if((trList[a].id == 'Tracability')||(trList[a].id == 'Tracability2'))
							trList[a].style.display ='table';
							document.SROptions.C0.checked = false;
							ShowTestStatus();
					} 	
					else
					{			
						for(a = 0;a<trList.length;a++)
						if((trList[a].id == 'Tracability')||(trList[a].id == 'Tracability2'))
							trList[a].style.display='none';
							document.SROptions.C0.checked = true;
							ShowTestStatus();
					}
				} 
				
				function ShowTestStatus() 
				{
				 var tableList = document.getElementsByTagName("table");
				 box = eval("document.SROptions.C0"); 
					if(box.checked == true)
					{
						for(a=0;a<tableList.length;a++)
						 if(tableList[a].id == 'TestStatus')
							tableList[a].style.display ='table';
							document.SROptions.C1.checked = false;
							ShowRequirements();
					} 	
					else
					{			
						for(a = 0;a<tableList.length;a++)
						if(tableList[a].id == 'TestStatus')
							tableList[a].style.display='none';
							document.SROptions.C1.checked = true;
							ShowRequirements();
					}
				} 
				
				function ShowIssuesOnly() 
				{
				 var tList = document.getElementsByTagName("tr");
				 box = eval("document.SROptions.C2"); 
					if(box.checked == true)
					{
						for(a=0;a<tList.length;a++)
						 if(tList[a].id == 'OK')
							tList[a].style.display ='none';
					} 	
					else
					{			
						for(a = 0;a<tList.length;a++)
						if(tList[a].id == 'OK')
							tList[a].style.display='table-row';
					}
				
				var tList = document.getElementsByTagName("table");
				 box = eval("document.SROptions.C2"); 
					if(box.checked == true)
					{
						for(a=0;a<tList.length;a++)
						 if(tList[a].id == 'Tracability2')
							tList[a].style.display ='none';
					} 	
					else
					{			
						for(a = 0;a<tList.length;a++)
						if(tList[a].id == 'Tracability2')
							tList[a].style.display='table';
					}
				} 
				
				
				function ShowNAOnly() 
				{
				 var tList = document.getElementsByTagName("table");
				 box = eval("document.SROptions.C3");
				 box2 = eval("document.SROptions.C0");
				 box3 = eval("document.SROptions.C1");
					if(box2.checked == true)
					{
						if (box.checked == true)
						{
					     for(a=0;a<tList.length;a++)
						 {
						 if(tList[a].id == 'TestStatus')
							tList[a].style.display ='none';
						 if(tList[a].id == 'Tracability2')
							tList[a].style.display ='table';
						 }
						
						} 	
						else
						{			
							for(a = 0;a<tList.length;a++)
							 {
							if(tList[a].id == 'TestStatus')
								tList[a].style.display ='table';
							if(tList[a].id == 'Tracability2')
								tList[a].style.display ='none';
							}
						}
					}
					if(box3.checked == true)
					{
						if (box.checked == true)
						{
					     for(a=0;a<tList.length;a++)
						 {
						 if(tList[a].id == 'Tracability')
							tList[a].style.display ='none';
						 if(tList[a].id == 'Tracability2')
							tList[a].style.display ='table';
						 }
						
						} 	
						else
						{			
							for(a = 0;a<tList.length;a++)
							 {
							if(tList[a].id == 'Tracability')
								tList[a].style.display ='table';
							if(tList[a].id == 'Tracability2')
								tList[a].style.display ='none';
							}
						}
						
					}
					
					
				 var tList = document.getElementsByTagName("tr");
				 box = eval("document.SROptions.C3"); 
					if(box.checked == true)
					{
						for(a=0;a<tList.length;a++)
						 if((tList[a].id == 'NT')||(tList[a].id == 'MT'))
							tList[a].style.display ='none';
					} 	
					else
					{			
						for(a = 0;a<tList.length;a++)
						if((tList[a].id == 'NT')||(tList[a].id == 'MT'))
							tList[a].style.display='table-row';
					}	
					
				}
				
				
				
				]]>
	
				</script>

				<style type="text/css">
				
					
					
					
					x.padding
						{
						padding-left:5px;
						padding-right:5px;
						}
						
					x.commentpadding
						{
						padding-left:5px;
						padding-right:5px;
						padding-top:5px;
						padding-bottom:5px;
						}
					
					x.nopadding
						{
						padding-left:0px;
						padding-right:0px;
						}
						
					x.passed
						{
						padding-left:10px;
						padding-right:10px;
						padding-top:1px;
						padding-bottom:1px;
						background-color:green;
						}

					x.passedfont
						{
						padding-left:2px;
						padding-right:2px;
						font-color:green;
						}
						
					x.failed
						{
						padding-left:10px;
						padding-right:10px;
						padding-top:1px;
						padding-bottom:1px;
						background-color:red;
						}
						
					x.failedfont
						{
						padding-left:2px;
						padding-right:2px;
						font-color:green;
						}	
						
					table.ex
						{
						border:2px solid black;
						font-family:arial;
						font-size:11pt;
						text-align: left;
						}
						
					td.outset 
						{
						border-bottom-style:solid; 
						border-left-style:hidden; 
						border-right-style:hidden; 
						border-bottom-color:#AFDCEC; 
						border-left-color:#AFDCEC;
						border-right-color:#AFDCEC;
						border-bottom-width:2px; 
						border-left-width:1px; 
						border-right-width:1px;
						}
						
					td.comment 
						{
						border-bottom-style:solid; 
						border-left-style:hidden; 
						border-right-style:hidden; 
						border-bottom-color:#99FDD7; 
						border-left-color:#99FDD7;
						border-right-color:#99FDD7;
						border-bottom-width:1px; 
						border-left-width:1px; 
						border-right-width:1px;
						}
	
				</style>
			</head>
			<body bgcolor = "white" link="black" vlink="black" alink="#FF0000" onload="ShowRequirements()">
				<br/>
				<table border="1" width="100%"
					style="border-width: 2px;
						border-spacing: 1px;
						border-style: inset;
						border-color: black;
						border-collapse: collapse;
						background-color: white;">
					<tbody>
						<tr bgcolor="#CCCCCC">
							<td style="border-color:#000000; " align="center" width="20%">
								<span style="font-family:Arial; font-size:xx-large; font-weight:bold; color:#151B8D"> SWV</span>
							</td>
							<td style="border-color:#000000; " align="center" colspan="3">
								<span style="font-size:xx-large; color:#151B8D">
									<b>Summary Report</b>
								</span>
							</td>
							<td style="border-color:#000000; -moz-border-radius:0px;" align="left" valign="middle"
								width="20%" bgcolor="white" rowspan="2">
								<img border="0">
									<xsl:attribute name="src">
										<xsl:text disable-output-escaping="yes">file:///G://98_Projects//031_NeEva//Style//autoliv.bmp</xsl:text>
									</xsl:attribute>
								</img>
							</td>
						</tr>
						<tr bgcolor="#CCCCCC">
						<td style="border-color:#000000; " align="center" width="20%">
						<span style="font-family:Arial; font-size:small; font-weight:bold; color:#151B8D">Options</span>
						</td>
						<td align="center">
						<form name="SROptions">
									<input type="checkbox" name="C0" checked="Yes" onclick="ShowTestStatus()"/>
									<font type="arial" size="2">View Test Status</font>
									<input type="checkbox" name="C1" onclick="ShowRequirements()"/>
									<font type="arial" size="2">View Tracability</font>
									<input type="checkbox" name="C2" onclick="ShowIssuesOnly()" />
									<font type="arial" size="2">View Issues Only</font>
									<input type="checkbox" name="C3" onclick="ShowNAOnly()" />
									<font type="arial" size="2">View NA Requirements Only</font>
						</form>
						</td>
						</tr>
					</tbody>
				</table>
				<table border="0" width="100%">
					<tbody>
						<tr>
							<td style="border: 0px;" align="left" >  </td>
							<td style="border: 0px;" align="center">
								<br /><br />
								<tr>
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Project: </b>
									<xsl:for-each select="Results/Header">
										<xsl:value-of select="Project"/>
									</xsl:for-each>
								</span>
								</tr>
								<tr>
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Software Version: </b>
									<xsl:for-each select="Results/Header">
										<xsl:value-of select="SoftwareVersion"/>
									</xsl:for-each>
								</span>
								</tr>
								<tr>
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Module Name: </b>
									<xsl:for-each select="Results/Header">
										<xsl:value-of select="ModuleName"/>
									</xsl:for-each>
								</span>
								</tr>
								<tr>
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Tester Name: </b>
									<xsl:for-each select="Results/Header">
										<xsl:value-of select="TesterName"/>
									</xsl:for-each>
								</span>
								<br /><br />
								</tr>
							</td>
							<td style="border: 0px;" align="right">  </td>
						</tr>
					</tbody>
				</table>
				<center>
				<table id="TestStatus" cellspacing="0px" cellpadding="1px" border="0" class="ex">
					<tbody>
						<tr bgcolor="#CCCCCC" align="center">
							<th style="border: 1px solid black;">
								<font color="#151B8D">Test Nr.</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Test Name</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Description</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Status</font>
							</th>
						</tr>
					</tbody>					
					<xsl:for-each select="comment()">
						<xsl:if test="name()!='Results'">
							<xsl:if test="string-length(normalize-space(.))!=0">
								<tr id="header" bgcolor="#EEECEC">
									<td colspan="4">
										<font color="#339933">
											<xsl:call-template name="break"> </xsl:call-template>
										</font>
									</td>
									<td>
										<div align="center">-</div>
									</td>
								</tr>
							</xsl:if>
						</xsl:if>
					</xsl:for-each>
					<xsl:for-each select="Results/Action | Results//comment() ">
							<xsl:if test="name()='Action'">
								<xsl:if test="Result='NOK'">
									<tr title = "Summary" id="NOK">
										<td class="outset"><center><x class="padding" style="color:blue;"><xsl:value-of select="Test"/></x></center></td>
										<td class="outset"><x class="padding" style="color:green;"><a style="color:green;" STYLE="text-decoration:none" href="..\scn\{Testname}.ts" target="_blank"><xsl:value-of select="Testname"/></a></x></td>
										<td class="outset"><x class="padding" style="color:red;"><xsl:value-of select="Description"/> </x></td>
										<td class="outset" bgcolor="red"><center><x class="failed"><a style="color:green;" STYLE="text-decoration:none" href="neg\{Testname}.xml" target="_blank"><b><xsl:value-of select="Result"/></b></a></x></center></td>
									</tr>
									<tr id="NOK">
									<td class="outset" colspan="2"><center><x class="padding" style="color:blue;">Issue Number:Name(Date) </x></center></td>
									<td class="outset" colspan="2"><x class="padding" style="color:red;"><b style="color:black;"><a style="color:green;" STYLE="text-decoration:none" href="http://ALVA-MKS03.alv.autoliv.int:7001/im/issues?selection={substring(Issue, 1, 5)}" target="_blank"><xsl:value-of select="Issue"/></a></b></x></td>
									</tr>
								</xsl:if>
								<xsl:if test="Result='OK'">
									<tr title = "Summary" id="OK">
										<td class="outset"><center><x class="padding" style="color:blue;"><xsl:value-of select="Test"/></x></center></td>
										<td class="outset"><x class="padding" style="color:green;"><a style="color:green;" STYLE="text-decoration:none" href="..\scn\{Testname}.ts" target="_blank"><xsl:value-of select="Testname"/></a></x></td>
										<td class="outset"><x class="padding" style="color:green;"><xsl:value-of select="Description"/> </x></td>
										<td class="outset" bgcolor="green"><center><x class="passed"><a style="color:green;" STYLE="text-decoration:none" href="OK\{Testname}.xml" target="_blank"><b><xsl:value-of select="Result"/></b></a></x></center></td>
									</tr>
								</xsl:if>
								<xsl:if test="Result='OK '">
									<tr title = "Summary" id="OK">
									<td class="outset"><center><x class="padding" style="color:blue;"><xsl:value-of select="Test"/></x></center></td>
									<td class="outset"><x class="padding" style="color:green;"><a style="color:green;" STYLE="text-decoration:none" href="..\scn\{Testname}.ts" target="_blank"><xsl:value-of select="Testname"/></a></x></td>
									<td class="outset"><x class="padding" style="color:green;"><xsl:value-of select="Description"/> </x></td>
									<td class="outset" bgcolor="green"><center><x class="passed"><a style="color:green;" STYLE="text-decoration:none" href="neg\{Testname}.xml" target="_blank"><b>OK</b></a></x></center></td>
									</tr>
								</xsl:if>	
							</xsl:if>
							<xsl:if test="name()!='Action'">
								<xsl:if test="string-length(normalize-space(.))!=0">
									<tr  title = "binit" id="row_comments">
										<td colspan="4" class="comment"><x class="commentpadding">
											<font color="#347C2C">
												<xsl:value-of select="normalize-space(.)"/>
											</font></x>
										</td>
										<td class="comment">
											<div align="center">-</div>
										</td>
									</tr>
								</xsl:if>
							</xsl:if>
					</xsl:for-each>
				</table>
				<table id="TestStatus" border="0" width="100%">
					<tbody>
						<tr>
							<td style="border: 0px;" align="left" >  </td>
							<td style="border: 0px;" align="center">
								<br /><br />
								<tr>
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Number of Tests: </b>
									<xsl:for-each select="Results/FinalStatus">
										<xsl:value-of select="TotalTests"/>
									</xsl:for-each>
								</span>
								</tr>
								<tr id="OK">
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Number of positive tests: </b>
									<xsl:for-each select="Results/FinalStatus">
										<xsl:value-of select="PozitiveTests"/>
									</xsl:for-each>
								</span>
								</tr>
								<tr id="NOK">
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Number of negative tests: </b>
									<xsl:for-each select="Results/FinalStatus">
										<xsl:value-of select="NegativeTests"/>
									</xsl:for-each>
								</span>
								</tr>
								<br /><br />
							</td>
							<td style="border: 0px;" align="right">  </td>
						</tr>
					</tbody>
				</table>
						
								
				<table id="Tracability" cellspacing="0px" cellpadding="1px" border="0" class="ex">
					<tbody>
						<tr bgcolor="#CCCCCC" align="center">
							<th style="border: 1px solid black;">
								<font color="#151B8D">Test Nr.</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Test Name</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Tracability</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Status</font>
							</th>
						</tr>
					</tbody>					
					<xsl:for-each select="Results/Action | Results//comment() ">
							<xsl:if test="name()='Action'">
								<xsl:if test="Result='NOK'">
									<tr title = "Summary" id="NOK">
									<td class="outset"><center><x class="padding" style="color:blue;"><xsl:value-of select="Test"/></x></center></td>
									<td class="outset"><x class="padding" style="color:green;"><a style="color:green;" STYLE="text-decoration:none" href="..\scn\{Testname}.ts" target="_blank"><xsl:value-of select="Testname"/></a></x></td>
									<td class="outset"><x class="padding" style="color:red; font-size:9pt;"><xsl:value-of select='translate(Requirement,","," ")'/></x></td>
									<td class="outset" bgcolor="red"><center><x class="failed"><a style="color:green;" STYLE="text-decoration:none" href="neg\{Testname}.xml" target="_blank"><b><xsl:value-of select="Result"/></b></a></x></center></td>
									</tr>
								</xsl:if>
								<xsl:if test="Result='OK'">
									<tr title = "Summary" id="OK">
									<td class="outset"><center><x class="padding" style="color:blue;"><xsl:value-of select="Test"/></x></center></td>
									<td class="outset"><x class="padding" style="color:green;"><a style="color:green;" STYLE="text-decoration:none" href="..\scn\{Testname}.ts" target="_blank"><xsl:value-of select="Testname"/></a></x></td>
									<td class="outset"><x class="padding" style="color:green; font-size:9pt;"><xsl:value-of select='translate(Requirement,","," ")'/></x></td>
									<td class="outset" bgcolor="green"><center><x class="passed"><a style="color:green;" STYLE="text-decoration:none" href="OK\{Testname}.xml" target="_blank"><b><xsl:value-of select="Result"/></b></a></x></center></td>
									</tr>
								</xsl:if>
								<xsl:if test="Result='OK '">
									<tr title = "Summary" id="OK">
									<td class="outset"><center><x class="padding" style="color:blue;"><xsl:value-of select="Test"/></x></center></td>
									<td class="outset"><x class="padding" style="color:green;"><a style="color:green;" STYLE="text-decoration:none" href="..\scn\{Testname}.ts" target="_blank"><xsl:value-of select="Testname"/></a></x></td>
									<td class="outset"><x class="padding" style="color:green; font-size:9pt;"><xsl:value-of select='translate(Requirement,","," ")'/></x></td>
									<td class="outset" bgcolor="green"><center><x class="passed"><a style="color:green;" STYLE="text-decoration:none" href="neg\{Testname}.xml" target="_blank"><b>OK</b></a></x></center></td>
									</tr>
								</xsl:if>	
							</xsl:if>
					</xsl:for-each>
				</table>
				<br />
				<br />
				
				<table id="Tracability2" cellspacing="0px" cellpadding="1px" border="0" class="ex">
					<tbody>
						<tr bgcolor="#CCCCCC" align="center">
							<th style="border: 1px solid black;">
								<font color="#151B8D">Requirement</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Comment</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Status</font>
							</th>
						</tr>
					</tbody>					
					<xsl:for-each select="Results/Req">
								<xsl:if test="Status='NA'">
									<tr title = "Summary" id="NA">
									<td class="outset"><x class="padding" style="font-size:9pt;"><xsl:value-of select='Requirement'/></x></td>
									<td class="outset"><x class="padding" style="color:#DF7401;"><xsl:value-of select="Comment"/></x></td>
									<td class="outset" bgcolor="#DF7401"><center><x class="padding"><b>Not Applicable</b></x></center></td>
									</tr>
								</xsl:if>
								<xsl:if test="Status='NT'">
									<tr title = "Summary" id="NT">
									<td class="outset"><x class="padding" style="font-size:9pt;"><xsl:value-of select='Requirement'/></x></td>
									<td class="outset"><x class="padding" style="color:red;"><xsl:value-of select="Comment"/></x></td>
									<td class="outset" bgcolor="red"><center><x class="padding"><b>Not Tested</b></x></center></td>
									</tr>
								</xsl:if>
								<xsl:if test="Status='MT'">
									<tr title = "Summary" id="MT">
									<td class="outset"><x class="padding" style="font-size:9pt;"><xsl:value-of select='Requirement'/></x></td>
									<td class="outset"><x class="padding" style="color:green;"><xsl:value-of select="Comment"/></x></td>
									<td class="outset" bgcolor="green"><center><x class="passed"><b>Manually Tested</b></x></center></td>
									</tr>
								</xsl:if>
					</xsl:for-each>
				</table>
				
				
				<table id="Tracability2" border="0" width="100%">
					<tbody>
						<tr>
							<td style="border: 0px;" align="left" >  </td>
							<td style="border: 0px;" align="center">
								<br /><br />
								<tr id ="NT">
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Requirements Not Tested: </b>
									<xsl:for-each select="Results/RequirementStatus">
										<xsl:value-of select="RequirementsNotTested"/>
									</xsl:for-each>
								</span>
								</tr>
								<tr id="NA">
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Requirements Not Applicable: </b>
									<xsl:for-each select="Results/RequirementStatus">
										<xsl:value-of select="RequirementsNotApplicable"/>
									</xsl:for-each>
								</span>
								</tr>
								<tr id="MT">
								<span style="font-size:x-large;">
									<b style="color:#151B8D">Requirements Manually Tested: </b>
									<xsl:for-each select="Results/RequirementStatus">
										<xsl:value-of select="RequirementsManuallyTested"/>
									</xsl:for-each>
								</span>
								</tr>
								<br /><br />
							</td>
							<td style="border: 0px;" align="right">  </td>
						</tr>
					</tbody>
				</table>
				
				
				
				
				</center>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>

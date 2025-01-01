<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
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
					<xsl:when test="contains(substring-before($text, '&#xa;'),'TOBEANALYSED')">
						<font color="#EEEA31">
							<blink><xsl:value-of select="substring-before($text, '&#xa;')"/></blink>
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
                function enableHeader() {
                    box = eval("document.checkboxform1.C1");
                    if (box.checked == true) {
                        document.getElementById('header').style.display = 'table-row';
                    } else {
                        document.getElementById('header').style.display = 'none';
                    }
                }<![CDATA[
				
				function disableComments() 
				{
				 var trList = document.getElementsByTagName("tr");
				 box = eval("document.checkboxform2.C2"); 
					if(box.checked == true)
					{
						for(a=0;a<trList.length;a++)
							if(trList[a].id == 'row_comments')
							{
								if(trList[a].innerHTML.search(/id="links">STEP/i) < 0)
								{
									trList[a].style.display ='none';
								}
							}
					} 	
					else
					{			
						for(a = 0;a<trList.length;a++)
						if(trList[a].id == 'row_comments')
							trList[a].style.display='table-row';
					}
				} 
				
				function disableBenchInit() 
				{
				 var trList = document.getElementsByTagName("tr");
				 for(a=0;a<trList.length;a++)
					{
						result_temp = trList[a].innerHTML.search(/start_testing_procedure/i);
						if(result_temp>=0)
						{break;}
					}
				 var trList = document.getElementsByTagName("tr");
				 box = eval("document.checkboxform3.C3"); 
				if(box.checked == true)
						{
							if(result_temp>=0)
							    {
									for(a=0;a<trList.length;a++)
									{
										if(trList[a].title == 'binit')
											trList[a].style.display ='none';
										result = trList[a].innerHTML.search(/start_testing_procedure/i);
										if(result>=0)
										{
											trList[a].style.display ='table-row';
											break;
										}
									}	
								}	
						} 	
						else
						{			
						for(a = 0;a<trList.length;a++)
							if(trList[a].title == 'binit')
							{
								trList[a].style.display='table-row';
								
							}
						}
				} 
				
				function boldSteps()
				{
					var trList = document.getElementsByTagName("td");
					for(a=0;a<trList.length;a++)
					{
						if(trList[a].id == 'col_comments')
						{
							result_temp_1 = trList[a].innerHTML.search(/step /i);
							result_temp_2 = trList[a].innerHTML.search(/Action: /i);
							result_temp_3 = trList[a].innerHTML.search(/Expect: /i);
							if (result_temp_1>=0)
							{
								trList[a].style.color = "#042DE5";
								trList[a].style.fontStyle = 'italic';
								trList[a].style.fontWeight = 'bold';
								
								//Temp fix for Action/Expect remove
								
								trList[a+1].style.fontWeight = 'bold';
								trList[a+1].style.fontStyle = 'italic';
								trList[a+1].style.color = "#008033";
								trList[a+2].style.fontWeight = 'bold';
								trList[a+2].style.fontStyle = 'italic';
								trList[a+2].style.color = "#008033";
								a=a+2;
							}
							/*else
							if((result_temp_2 >= 0) || (result_temp_3 >= 0))
							{
								trList[a].style.fontWeight = 'bold';
								trList[a].style.fontStyle = 'italic';
								trList[a].style.color = "#008033";
							}*/
							else
							{
								trList[a].style.color = "#339933";
							}
						}
					}				
				}

				function readfile_ie(srcfile)
				{
					var fso = new ActiveXObject("Scripting.FileSystemObject");
					var s = fso.OpenTextFile(srcfile, 1, true); 
					return s.readAll();
				}

				function readfile(srcfile) 
				{
					try 
					{
						netscape.security.PrivilegeManager.enablePrivilege("UniversalXPConnect");
					} 
					catch (e)
					{
						//alert("Permission to read file was denied.");
					}
					var file = Components.classes["@mozilla.org/file/local;1"].createInstance(Components.interfaces.nsILocalFile);
					file.initWithPath( srcfile );
					if (file.exists() == false) 
					{
					}
					var is = Components.classes["@mozilla.org/network/file-input-stream;1"].createInstance( Components.interfaces.nsIFileInputStream );
					is.init( file,0x01, 00004, null);
					var sis = Components.classes["@mozilla.org/scriptableinputstream;1"].createInstance( Components.interfaces.nsIScriptableInputStream );
					sis.init(is);
					var output = sis.read(sis.available());
					return output;
					}
			
				function onloadFunctions()
				{
					enableHeader();
					disableBenchInit();
					boldSteps();
					init_links();
					findLineNumber();
				}

				function getTs_ie()
				{
					testpath = "";
					filename = "";
					outputPath = window.location.pathname.replace("file:///","");
					
					outputPath = outputPath.replace("#","");
					splitted = outputPath.split("/");
					for (i=1;i<splitted.length-3;i++)
						testpath = testpath + splitted[i]+'/';
					testpath = testpath+"Scripts/";
					if (splitted[splitted.length-2] !="LastOutput")
						for (i=0;i<(splitted[splitted.length-1].length)-13;i++)
							filename = filename+splitted[splitted.length-1].charAt(i);
					else
						for (i=0;i<(splitted[splitted.length-1].length)-4;i++)
							filename = filename+splitted[splitted.length-1].charAt(i);
							
					return testpath+filename+".ts";
				}

				
				function getTs()
				{
					testpath = "";
					filename = "";
					outputPath = window.content.location.href.replace("file:///","");
					outputPath = outputPath.replace("#","");					
					splitted = outputPath.split("/");
					for (i=0;i<splitted.length-3;i++)
						testpath = testpath + splitted[i]+'\\';
					testpath = testpath+"Scripts\\";
					if (splitted[splitted.length-2] !="LastOutput")
						for (i=0;i<splitted[splitted.length-1].length-13;i++)
							filename = filename+splitted[splitted.length-1][i];
					else
						for (i=0;i<splitted[splitted.length-1].length-4;i++)
							filename = filename+splitted[splitted.length-1][i];
						
					return testpath+filename+".ts";
				}
				
				function findLineNumber(line)
				{	
					if (navigator.appName == "Netscape")
					{
						buffer = readfile(getTs());
					}
					else
					{
						buffer = readfile_ie(getTs_ie());
					}
					i = 0;
					bufrer = buffer.replace("\n","");
					lines = buffer.split("\r");
					for (tmpline=0;tmpline<lines.length;tmpline++)
					{
						if(lines[tmpline].trim().search("//") < 0) 
						{
							if ((lines[tmpline].search("CommentStep") >=0) || (lines[tmpline].search("ResultStep")>=0))
							{
								i = i+1;
								if (i.toString()==line)
								{
									break;
								}
							}
						}
					}
					return "-n"+(tmpline+1).toString();
				}
				
				function launchEditor(step)
				{
					var n = navigator;
					var ua = ' ' + n.userAgent.toLowerCase();
					if (ua.search(/windows nt 6.1/i) >=0)
						notepad_path = "c:\\Program Files (x86)\\Notepad++\\notepad++.exe"
					else
						notepad_path = "c:\\Program Files\\Notepad++\\notepad++.exe"
				
					if (navigator.appName == "Netscape")
					{
						step_number = step.split(" ")[1].split(":")[0];
						netscape.security.PrivilegeManager.enablePrivilege("UniversalXPConnect");
						var exe = window.Components.classes['@mozilla.org/file/local;1'].createInstance(Components.interfaces.nsILocalFile);
						exe.initWithPath(notepad_path);
						var run = window.Components.classes['@mozilla.org/process/util;1'].createInstance(Components.interfaces.nsIProcess);
						run.init(exe);
						var parameters = [findLineNumber(step_number),getTs()];
						run.run(false, parameters,parameters.length);
					}
					else
					{
						step_number = step.split(" ")[1].split(":")[0];
						findLineNumber(step_number);
						var WshShell = new ActiveXObject("WScript.Shell");
						WshShell.Exec(notepad_path+" "+getTs_ie()+" "+findLineNumber(step_number));
						WshShell.Quit;
					}
				}
				
				function init_links()
				{
					var linkList = document.getElementsByTagName("a");
					result_temp_1 = -1;
					for(a=0;a<linkList.length;a++)
						{
							if(linkList[a].id == 'links')
							{
								result_temp_1 = linkList[a].innerHTML.search(/step /i);
								if (result_temp_1>=0)
								{	
									linkList[a]['href']="#";
								}
								else
								{
									linkList[a].onclick=function x(){return false;};
								}
							}
						}	
				}				
				
				]]>
    			</script>

				<style type="text/css">
					td {
					    font-family: arial;
					    border: 1px solid white;
					    -moz-border-radius:0px;
					    font-size:small
					}
					font {
					    font-family: arial;
					}
				 	thead {
				 	    display:table-header-group;
				 	}
				</style>
			</head>
			<body vlink = "blue" bgcolor = "white" onload="onloadFunctions()">
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
							<td style="border-color:#000000; " align="center" width="6%">
								<span
									style="font-family:Arial; font-size:x-large; font-weight:bold; color:#151B8D"
									> SWV</span>
							</td>
							<td style="border-color:#000000; " align="center">
								<span style="font-size:x-large; color:#151B8D">
									<b>Test Report: </b>
									<xsl:for-each select="comment()">
										<xsl:if test="name()!='Results'">
											<xsl:if test="string-length(normalize-space(.))!=0">
												<xsl:call-template name="test_name">
												<xsl:with-param name="text" select="."/>
												</xsl:call-template>
											</xsl:if>
										</xsl:if>
									</xsl:for-each>
								</span>
							</td>
							<td style="border-color:#000000; -moz-border-radius:0px;" align="left" valign="middle"
								width="15%" bgcolor="white">
								<img border="0">
									<xsl:attribute name="src">
										<xsl:text disable-output-escaping="yes">file:///g://04_Projects//021_Communication//NeEva Macro Test Library//Tools//Style//autoliv.bmp</xsl:text>
									</xsl:attribute>
								</img>
							</td>
						</tr>
					</tbody>
				</table>
				<br/>
				<br/>
				<table border="0" width="100%">
					<tbody>
						<tr>
							<td style="border: 0px;" align="left" width="20%">
								<form name="checkboxform1">
									<input type="checkbox" name="C1" onclick="enableHeader()"/>
									<font type="arial" size="2">View Header Comment</font>
									<br/>
								</form>
								<form name="checkboxform2">
									<input type="checkbox" name="C2" onclick="disableComments()"/>
									<font type="arial" size="2">Disable All Comments</font>
									<br/>
								</form>
								<form name="checkboxform3">
									<input type="checkbox" name="C3" onclick="disableBenchInit()" checked = "Yes"/>
									<font type="arial" size="2">Disable Bench Init</font>
									<br/>
								</form>								
							</td>
							<td style="border: 0px;" align="center"> </td>
							<td style="border: 0px;" align="right" valign="bottom" width="40%">
								<font size="5" color="#151B8D">  <b>Final Test Result:   </b><xsl:for-each
										select="comment()">
										<xsl:if test="name()!='Results'">
											<xsl:if test="string-length(normalize-space(.))!=0">
												<b>
												<xsl:call-template name="test_result">
												<xsl:with-param name="text" select="."/>
												</xsl:call-template>
												</b>
											</xsl:if>
										</xsl:if>
									</xsl:for-each>
								</font>
							</td>
						</tr>
					</tbody>
				</table>

				<table width="100%" class="" cellSpacing="1" cellPadding="0" border="1"
						style="border-width: 2px;
						border-spacing: 1px;
						border-style: inset;
						border-color: black;
						border-collapse: collapse;
						background-color: white;">
					<thead>
						<tr bgcolor="#CCCCCC">
							<th style="border: 1px solid black;">
								<font color="#151B8D">Time</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Action Name</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Expected</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Obtained</font>
							</th>
							<th style="border: 1px solid black;">
								<font color="#151B8D">Step Status</font>
							</th>
						</tr>
					</thead>
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
					<xsl:for-each select="Results/Action | Results/comment">
							<xsl:if test="name()='Action'">
								<xsl:if test="Result='Failed'">
									<tr title = "binit">
										<td bgcolor="#CCCCCC"><xsl:value-of select="Timestamp"/> </td>
										<td bgcolor="#CCCDDD"><font color="#151B8D"><xsl:value-of
													select="@Name"/></font> </td>
										<td
											style="background:#CCCEEE"
												><xsl:value-of select="Expected"/> </td>
										<td
											style="background:#CCBAFE"
												><xsl:value-of select="Obtained"/> </td>
										<td
											style="text-align:center; background:#FF0000">
											<b>
												<xsl:value-of select="Result"/>
											</b>
										</td>
									</tr>
								</xsl:if>
								<xsl:if test="Result='Passed'">
									<tr title = "binit">
										<td bgcolor="#CCCCCC"><xsl:value-of select="Timestamp"/> </td>
										<td bgcolor="#CCCDDD"><font color="#151B8D"><xsl:value-of
													select="@Name"/></font> </td>
										<td
											style="background:#CCCEEE"
												><xsl:value-of select="Expected"/> </td>
										<td
											style="background:#CCBAFE"
												><xsl:value-of select="Obtained"/> </td>
										<td
											style="text-align:center; background:#00A000">
											<b>
												<xsl:value-of select="Result"/>
											</b>
										</td>
									</tr>
								</xsl:if>
								<xsl:if test="Result=''">
									<tr title = "binit">
										<td bgcolor="#CCCCCC"><xsl:value-of select="Timestamp"/> </td>
										<td bgcolor="#CCCDDD"><font color="#151B8D"><xsl:value-of
													select="@Name"/></font> </td>
										<td
											style="background:#CCCEEE"
												><xsl:value-of select="Expected"/> </td>
										<td
											style="background:#CCBAFE"
												><xsl:value-of select="Obtained"/> </td>
										<td style="-moz-border-radius:0px;" bgcolor="#EEECEC" align = "center">-
										</td>
									</tr>
								</xsl:if>							
							</xsl:if>
							<xsl:if test="name()='comment'">
								<xsl:choose>
								<xsl:when test="contains(text(),'STEP ')">
									<tr  title = "binit" bgcolor="#EEECEC" id="row_comments">
										<td id="col_comments">
										<a id = "links" onclick = "launchEditor(this.innerHTML);return false;"><xsl:value-of select="."/></a>
										</td>
										<td id="col_comments">
										<a id = "links" onclick = "launchEditor(this.innerHTML);return false;"><xsl:value-of select="substring-after(following-sibling::comment[1],'Action: ')"/></a>
										</td>
										<td id="col_comments">
										<xsl:if test="contains(following-sibling::comment[2],'Expect:')">
										<a id = "links" onclick = "launchEditor(this.innerHTML);return false;"><xsl:value-of select="substring-after(following-sibling::comment[2],'Expect: ')"/></a>
										</xsl:if>
										</td>
										<td id="col_comments">
										</td>
										<td id="col_comments">
											<div align="center">-</div>
										</td>
									</tr>
								</xsl:when>
								<xsl:when test="contains(text(),'Action:')">
								<!-- Dont display Action because its displayed after Action Above -->
								</xsl:when>
								<xsl:when test="contains(text(),'Expect:')">
								<!-- Dont display Expect because its displayed after Action Above -->
								</xsl:when>
								<xsl:otherwise>
									<tr  title = "binit" bgcolor="#EEECEC" id="row_comments">
										<td colspan="4" id="col_comments">
										<a id = "links" onclick = "launchEditor(this.innerHTML);return false;"><xsl:value-of select="."/></a>
										</td>
										<td id="col_comments">
											<div align="center">-</div>
										</td>
									</tr>
								</xsl:otherwise>
								</xsl:choose>
								
							</xsl:if>
					</xsl:for-each>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>

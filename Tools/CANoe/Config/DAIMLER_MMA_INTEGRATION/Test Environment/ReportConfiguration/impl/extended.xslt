<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:exsl="http://exslt.org/common" exclude-result-prefixes="exsl" extension-element-prefixes="exsl">  
  
  <xsl:template match="*" mode="show-hide"/>
  <xsl:template match="*" mode="end"/>
  
  <!-- Template: Test Module Information section -->
  <xsl:template match="testmodule" mode="information">
    <xsl:call-template name="testmodule-information"/>
  </xsl:template>
  <xsl:template match="testmodule" mode="tree">
    <xsl:param name="parent-obj" select="'objTree.root'"/>
    testcase = <xsl:value-of select="$parent-obj"/>.addChild("../common_report_files/info.gif", "Test Module Information", true, "Frame_Report.html#TestModuleInfo", "Report", "0");
    <xsl:apply-templates select="preparation|completion" mode="tree">
      <xsl:with-param name="parent-obj" select="$parent-obj"/>
      <xsl:with-param name="title" select="'Test Module'"/>
    </xsl:apply-templates>
    <xsl:apply-templates select="testcase|testgroup|skipped" mode="tree">
      <xsl:with-param name="parent-obj" select="$parent-obj"/>
      <xsl:with-param name="parent-nr" select="''"/>
      <xsl:with-param name="start-nr" select="0"/>
    </xsl:apply-templates>
    <xsl:apply-templates select="(checkbegin|checkstartupinfo)[1]|(checkend|checkterminationinfo)[1]" mode="file"/>
  </xsl:template>
  <xsl:template match="testmodule" mode="report-end"/>
  <xsl:template match="testmodule" mode="href-file">
    <xsl:text>Frame_Report.html</xsl:text>
  </xsl:template>
  <xsl:template name="testmodule-information">
    <!-- Check statistics on test module level -->
    <xsl:if test="./checkstatistic">
      <div class="Heading4">
        <xsl:text>Test Module Check Statistics</xsl:text>
      </div>
      <xsl:apply-templates select="./checkstatistic" mode="report"/>
    </xsl:if>
    <!-- Violations -->
    <xsl:if test="violation|descendant::testcase/violation|descendant::testgroup/violation">
      <div class="Heading4">Violations occurred</div>
      <!-- ??? -->
      <xsl:if test="descendant::testcase/violation">
        <div class="Indentation">
          <table class="OverviewTable">
            <tr>
              <td class="DefineCell" colspan="4">Number of violations inside test cases:</td>
            </tr>
            <tr>
              <td class="DefineCell">Total number</td>
              <td class="NumberCell">
                <xsl:value-of select="count(descendant::testcase/violation)"/>
              </td>
            </tr>
            <xsl:variable name="tc-cond-v" select="count(descendant::testcase/violation[@type='condition' and (@result='fail' or @result='error')])"/>
            <xsl:variable name="tc-cons-v" select="count(descendant::testcase/violation[@type='constraint' and (@result='fail' or @result='error')])"/>
            <xsl:variable name="tc-cond-w" select="count(descendant::testcase/violation[@type='condition' and @result='warn'])"/>
            <xsl:variable name="tc-cons-w" select="count(descendant::testcase/violation[@type='constraint' and @result='warn'])"/>
            <xsl:variable name="tc-prog-v" select="count(descendant::testcase/violation[@type='program' and (@result='fail' or @result='error')])"/>
            <xsl:variable name="tc-prog-w" select="count(descendant::testcase/violation[@type='program' and @result='warn'])"/>
            <xsl:if test="$tc-cond-v > 0">
              <tr>
                <td class="NegativeResultCell" style="text-indent: {$IndentDepth}px;">Condition violation</td>
                <td class="NumberCell"><xsl:value-of select="$tc-cond-v"/></td>
              </tr>
            </xsl:if>
            <xsl:if test="$tc-cons-v > 0">
              <tr>
                <td class="NegativeResultCell" style="text-indent: {$IndentDepth}px;">Constraint violation</td>
                <td class="NumberCell"><xsl:value-of select="$tc-cons-v"/></td>
              </tr>
            </xsl:if>
            <xsl:if test="$tc-cond-w > 0">
              <tr>
                <td class="WarningCell" style="text-indent: {$IndentDepth}px;">Condition warning</td>
                <td class="NumberCell"><xsl:value-of select="$tc-cond-w"/></td>
              </tr>
            </xsl:if>
            <xsl:if test="$tc-cons-w">
              <tr>
                <td class="WarningCell" style="text-indent: {$IndentDepth}px;">Constraint warning</td>
                <td class="NumberCell"><xsl:value-of select="$tc-cons-w"/></td>
              </tr>
            </xsl:if>
            <xsl:if test="$tc-prog-v > 0">
              <tr>
                <td class="NegativeResultCell" style="text-indent: {$IndentDepth}px;">Program violation</td>
                <td class="NumberCell"><xsl:value-of select="$tc-prog-v"/></td>
              </tr>
            </xsl:if>
            <xsl:if test="$tc-prog-w">
              <tr>
                <td class="WarningCell" style="text-indent: {$IndentDepth}px;">Program warning</td>
                <td class="NumberCell"><xsl:value-of select="$tc-prog-w"/></td>
              </tr>
            </xsl:if>
          </table>
        </div>
      </xsl:if>
      <xsl:if test="violation|descendant::testgroup/violation">
        <div class="Indentation">
          <table class="OverviewTable">
            <td class="DefineCell" colspan="4">Violations outside of test cases:</td>
            <xsl:apply-templates select="violation|descendant::testgroup/violation" mode="testmodule"/>
          </table>
        </div>
      </xsl:if>
    </xsl:if>
    <xsl:apply-templates select="." mode="link-children"/>
  </xsl:template>
  <xsl:template match="testmodule" mode="link-children">
    <xsl:call-template name="link-children"/>
  </xsl:template>
  <xsl:template match="testmodule" mode="results">
    <xsl:apply-templates select="." mode="results-heading"/>
    <div class="Indentation">
      <table class="OverviewTable">
        <xsl:apply-templates select="/*/testcycle" mode="overview"/>
        <xsl:apply-templates select="preparation" mode="overview"/>
        <xsl:apply-templates select="/testreport/testunit|testgroup|testcase|skipped" mode="overview"/>
        <xsl:apply-templates select="completion" mode="overview"/>
      </table>
    </div>
  </xsl:template>

  <xsl:template match="testcycle" mode="information">
    <xsl:variable name="href">
      <xsl:apply-templates select="." mode="href-file"/>
    </xsl:variable>
    <exsl:document href="{$href}" method="html" indent="yes" doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
      <html>
        <head>
          <title>
            <xsl:value-of select="@run"/>
          </title>
          <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
        </head>
        <body>
          <xsl:apply-templates select="." mode="heading"/>
          <xsl:apply-templates select="." mode="detailed"/>
        </body>
      </html>
    </exsl:document>
  </xsl:template>
  <xsl:template match="testcycle" mode="href-file">
    <xsl:value-of select="generate-id()"/>
    <xsl:apply-templates select="." mode="html-name"/>
  </xsl:template>
  <xsl:template match="testcycle" mode="html-name">
    <xsl:text>cycleinfo.html</xsl:text>
  </xsl:template>
  <xsl:template match="testcycle[parent::testmodule]" mode="tree">
    testcycle = objTree.root.addChild("../common_report_files/testgroup.gif", "<xsl:text>Test Cycle </xsl:text><xsl:value-of select="@run"/>", false, "", "Report", "");
    testcycle.addChild("../common_report_files/info.gif", "Test Cycle Information", true, "<xsl:apply-templates select="." mode="href-file"/>", "Report", "");
    testgroup = testcycle
    <xsl:apply-templates select="preparation" mode="tree">
      <xsl:with-param name="parent-obj" select="'testcycle'"/>
      <xsl:with-param name="title" select="'Test Module'"/>
    </xsl:apply-templates>
    <xsl:apply-templates select="testcase|testgroup|skipped" mode="tree">
      <xsl:with-param name="parent-obj" select="'testgroup'"/>
    </xsl:apply-templates>
    <xsl:apply-templates select="completion" mode="tree">
      <xsl:with-param name="parent-obj" select="'testcycle'"/>
      <xsl:with-param name="title" select="'Test Module'"/>
    </xsl:apply-templates>
  </xsl:template>
  <xsl:template match="testcycle[parent::testmodule]" mode="detailed">
    <xsl:call-template name="testmodule-information"/>
  </xsl:template>
  <xsl:template match="testcycle" mode="link-children">
  </xsl:template>
  
  <xsl:template match="preparation|completion" mode="tree-icon">
    <xsl:choose>
      <xsl:when test="descendant::*[@result='error']">
        <xsl:text>"../common_report_files/testcase_error.gif"</xsl:text>
      </xsl:when>
      <xsl:when test="descendant::*[@result='fail']">
        <xsl:text>"../common_report_files/testcase_failed.gif"</xsl:text>
      </xsl:when>
      <xsl:when test="descendant::violation[(@result='fail' or @result='error') and @type!='observation']">
        <xsl:text>"../common_report_files/testcase_failed.gif"</xsl:text>
      </xsl:when>
      <xsl:when test="descendant::*[@result='inconclusive']">
        <xsl:text>"../common_report_files/testcase_inconclusive.gif"</xsl:text>
      </xsl:when>
      <xsl:when test="descendant::*[@result='pass']">
        <xsl:text>"../common_report_files/testcase_passed.gif"</xsl:text>
      </xsl:when>
      <xsl:otherwise>
        <xsl:text>"../common_report_files/testcase_none.gif"</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  <xsl:template match="preparation|completion" mode="tree">
    <xsl:param name="parent-obj"/>
    <xsl:param name="title" select="''"/>
    prepcomp = <xsl:value-of select="$parent-obj"/>.addChild(<xsl:apply-templates select="." mode="tree-icon"/>,"<xsl:apply-templates select="." mode="name"/>",true,"<xsl:apply-templates select="." mode="href-file"/>", "Report", "<xsl:value-of select="@timestamp"/>");
    <xsl:call-template name="preparation-completion-file">
      <xsl:with-param name="containerText" select="$title"/>
      <xsl:with-param name="withBeginEnd" select="true()"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="preparation|completion" mode="detailed">
    <xsl:param name="containerText"/>
    <xsl:param name="withBeginEnd"/>
    <xsl:call-template name="preparation-completion">
      <xsl:with-param name="containerText" select="$containerText"/>
      <xsl:with-param name="withBeginEnd" select="$withBeginEnd"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="preparation[parent::testcase]|completion[parent::testcase]">
    <xsl:param name="id"/>
    <xsl:call-template name="preparation-completion">
      <xsl:with-param name="id" select="$id"/>
      <xsl:with-param name="containerText">Test Case</xsl:with-param>
    </xsl:call-template>
  </xsl:template>
  <xsl:template name="preparation-completion-file">
    <xsl:param name="containerText"/>
    <xsl:param name="withBeginEnd" select="false()"/>
    <xsl:variable name="href">
      <xsl:apply-templates select="." mode="href-file"/>
    </xsl:variable>
    <exsl:document href="{$href}" method="html" indent="yes" doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
      <html>
        <head>
          <title>
            <xsl:apply-templates select="." mode="name-of"/>
            <xsl:value-of select="$containerText"/>
          </title>
          <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
          <xsl:call-template name="all-scripts"/>
        </head>
        <body>
          <xsl:apply-templates select="." mode="detailed">
            <xsl:with-param name="containerText" select="$containerText"/>
            <xsl:with-param name="withBeginEnd" select="$withBeginEnd"/>
          </xsl:apply-templates>
        </body>
      </html>
    </exsl:document>
  </xsl:template>
  <xsl:template match="preparation|completion" mode="href-file">
    <xsl:value-of select="generate-id(.)"/>
    <xsl:apply-templates select="." mode="html-name"/>
  </xsl:template>
  <xsl:template match="preparation" mode="html-name"> 
    <xsl:text>prep.html</xsl:text>
  </xsl:template>
  <xsl:template match="completion" mode="html-name"> 
    <xsl:text>comp.html</xsl:text>
  </xsl:template>
  
  <!-- Templates for Navigation Tree -->
  <xsl:template match="testgroup[count(descendant::testcase|descendant::testsequence)=0]" mode="tree">
    <xsl:param name="parent-obj"/>
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    <xsl:variable name="nr">
      <xsl:call-template name="make-number-impl">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="node-nr" select="$start-nr + $counted-nodes"/>
      </xsl:call-template>
    </xsl:variable>
    testcase = <xsl:value-of select="$parent-obj"/>.addChild("../common_report_files/testcase_skipped.gif","<xsl:value-of select="$nr"/><xsl:text> </xsl:text><xsl:value-of select="title"/>", false, "", "Report", "");
  </xsl:template>
  <xsl:template match="testgroup[count(descendant::testcase|descendant::testsequence)>0]" mode="tree">
    <xsl:param name="parent-obj"/>
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:apply-templates select="." mode="detailed">
      <xsl:with-param name="parent-nr" select="$parent-nr"/>
      <xsl:with-param name="start-nr" select="$start-nr"/>
    </xsl:apply-templates>
    
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    <xsl:variable name="nr">
      <xsl:call-template name="make-number-impl">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="node-nr" select="$start-nr + $counted-nodes"/>
      </xsl:call-template>
    </xsl:variable>
    <!-- add a group and information page -->
    testgroup = <xsl:value-of select="$parent-obj"/>.addChild("../common_report_files/testgroup.gif", "<xsl:value-of select="$nr"/><xsl:text> </xsl:text><xsl:value-of select="title"/>", false, "", "Report", "");
    testgroup.addChild("../common_report_files/info.gif", "Test Group Information", true, "<xsl:apply-templates select="." mode="href-file"/>", "Report", "");
    
    <xsl:apply-templates select="preparation|completion|testsequence|testcase|testgroup|testfixture|testsequencelist|testcaselist|skippedcase|skippedgroup|skippedfixture|skippedsequence|skippedtestcaselist|skippedtestsequencelist" mode="tree">
      <xsl:with-param name="parent-obj" select="'testgroup'"/>
      <xsl:with-param name="parent-nr" select="$nr"/>
      <xsl:with-param name="start-nr" select="0"/>
      <xsl:with-param name="title" select="'Test Group'"/>
    </xsl:apply-templates>
    
    <xsl:apply-templates select="(checkbegin|checkstartupinfo)[1]|(checkend|checkterminationinfo)[1]" mode="file"/>
    
    <!-- reset testgroup to parent testgroup when testgroup is not at uppermost level -->
    if (testgroup.parent != undefined)
    {
      testgroup = testgroup.parent;
    }
  </xsl:template>
  <xsl:template match="testgroup[count(descendant::testcase|descendant::testsequence)=0]" mode="detailed"/>
  <xsl:template match="testgroup[count(descendant::testcase|descendant::testsequence)>0]" mode="detailed">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:variable name="href">
      <xsl:apply-templates select="." mode="href-file"/>
    </xsl:variable>
    <exsl:document href="{$href}" method="html" indent="yes" doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
      <html>
        <head>
          <title>
            <xsl:value-of select="title"/>
          </title>
          <xsl:call-template name="all-scripts"/>
          <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
        </head>
        <body>
          <xsl:call-template name="testgroup-detailed">
            <xsl:with-param name="parent-nr" select="$parent-nr"/>
            <xsl:with-param name="start-nr" select="$start-nr"/>
          </xsl:call-template>
        </body>
      </html>
    </exsl:document>
  </xsl:template>
  <xsl:template name="testgroup-overview-impl">
    <a>
      <xsl:attribute name="href">
        <xsl:apply-templates select="." mode="href-file"/>
      </xsl:attribute>
      <b>
        <xsl:value-of select="title"/>
      </b>
    </a>
  </xsl:template>
  <xsl:template name="testgroup-detailed-impl">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:call-template name="link-children">
      <xsl:with-param name="parent-nr" select="$parent-nr"/>
      <xsl:with-param name="start-nr" select="0"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template name="testgroup-end-impl"/>
  <xsl:template match="testgroup" mode="href-file">
    <xsl:value-of select="generate-id(.)"/>
    <xsl:text>tginfo.html</xsl:text>
  </xsl:template>
  
  <xsl:template match="testcase[verdict/@result='error']" mode="tree-icon">
    <xsl:text>"../common_report_files/testcase_error.gif"</xsl:text>
  </xsl:template>
  <xsl:template match="testcase[verdict/@result='fail']" mode="tree-icon">
    <xsl:text>"../common_report_files/testcase_failed.gif"</xsl:text>
  </xsl:template>
  <xsl:template match="testcase[verdict/@result='inconclusive']" mode="tree-icon">
    <xsl:text>"../common_report_files/testcase_inconclusive.gif"</xsl:text>
  </xsl:template>  
  <xsl:template match="testcase[verdict/@result='pass']" mode="tree-icon">
    <xsl:text>"../common_report_files/testcase_passed.gif"</xsl:text>
  </xsl:template>
  <xsl:template match="testcase" mode="tree-icon">
    <xsl:text>"../common_report_files/testcase_none.gif"</xsl:text>
  </xsl:template>
  <xsl:template match="testcase" mode="tree">
    <xsl:param name="parent-obj"/>
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:apply-templates select="." mode="detailed">
      <xsl:with-param name="parent-nr" select="$parent-nr"/>
      <xsl:with-param name="start-nr" select="$start-nr"/>
    </xsl:apply-templates>
    <xsl:call-template name="testcase-tree">
      <xsl:with-param name="parent-obj" select="$parent-obj"/>
      <xsl:with-param name="parent-nr" select="$parent-nr"/>
      <xsl:with-param name="start-nr" select="$start-nr"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="testcase[./precondition/precondend[@fulfilled='false']]" mode="tree">
    <xsl:param name="parent-obj"/>
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:if test="$ShowFailedPreconditions">
      <xsl:apply-templates select="." mode="detailed">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr"/>
      </xsl:apply-templates>
      <xsl:call-template name="testcase-tree">
        <xsl:with-param name="parent-obj" select="$parent-obj"/>
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr"/>
      </xsl:call-template>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcase" mode="detailed">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:variable name="hide-tc">
      <xsl:call-template name="hidetestcase"/>
    </xsl:variable>
    <xsl:variable name="ShowTestCaseDetails" select="not(boolean(number($hide-tc)))"/>
    <xsl:if test="$ShowTestCaseDetails">
      <xsl:variable name="href">
        <xsl:apply-templates select="." mode="href-file"/>
      </xsl:variable>
      <exsl:document href="{$href}" method="html" indent="yes" doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
        <html>
          <head>
            <title>
              <xsl:value-of select="title"/>
            </title>
            <xsl:call-template name="all-scripts"/>
            <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
          </head>
          <body>
            <xsl:call-template name="testcase-detailed">
              <xsl:with-param name="parent-nr" select="$parent-nr"/>
              <xsl:with-param name="start-nr" select="$start-nr"/>
            </xsl:call-template>
          </body>
        </html>
      </exsl:document>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcase" mode="href-file">
    <xsl:value-of select="title"/>
    <xsl:text>.html</xsl:text>
  </xsl:template>
  <xsl:template name="testcase-tree">
    <xsl:param name="parent-obj"/>
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    <xsl:variable name="nr">
      <xsl:call-template name="make-number-impl">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="node-nr" select="$start-nr + $counted-nodes"/>
      </xsl:call-template>
    </xsl:variable>
    <xsl:variable name="hide-tc">
      <xsl:call-template name="hidetestcase"/>
    </xsl:variable>
    <xsl:variable name="ShowTestCaseLink" select="not(boolean(number($hide-tc)))"/>
    testcase = <xsl:value-of select="$parent-obj"/>.addChild(<xsl:apply-templates select="." mode="tree-icon"/>,"<xsl:value-of select="$nr"/><xsl:text> </xsl:text><xsl:value-of select="title"/>",<xsl:value-of select="$ShowTestCaseLink"/>,"<xsl:apply-templates select="." mode="href-file"/>","Report","<xsl:value-of select="@timestamp"/>");
  </xsl:template>
  
  <xsl:template match="skipped|skippedcase|skippedgroup|skippedfixture|skippedsequence|skippedtestcaselist|skippedtestsequencelist" mode="tree">
    <xsl:param name="parent-obj"/>
    skipped = <xsl:value-of select="$parent-obj"/>.addChild("../common_report_files/testcase_skipped.gif", "<xsl:value-of select="title"/>",false, "", "Report", "");
  </xsl:template>
  <xsl:template match="skipped|skippedcase|skippedgroup|skippedfixture|skippedsequence|skippedtestcaselist|skippedtestsequencelist" mode="detailed"/>
  
  <xsl:template match="checkbegin|checkstartupinfo" mode="file">
    <xsl:variable name="href">
      <xsl:apply-templates select="." mode="href-file"/>
    </xsl:variable>
    <exsl:document href="{$href}" method="html" indent="yes" doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
      <html>
        <head>
          <title>
            <xsl:text>Startup of checks</xsl:text>
          </title>
          <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
          <xsl:call-template name="all-scripts"/>
        </head>
        <body>
          <xsl:call-template name="checkstartup-head"/>
        </body>
      </html>
    </exsl:document>
  </xsl:template>
  <xsl:template match="checkend|checkterminationinfo" mode="file">
    <xsl:variable name="href">
      <xsl:apply-templates select="." mode="href-file"/>
    </xsl:variable>
    <exsl:document href="{$href}" method="html" indent="yes" doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
      <html>
        <head>
          <title>
            <xsl:text>Termination of checks</xsl:text>
          </title>
          <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
          <xsl:call-template name="all-scripts"/>
        </head>
        <body>
          <xsl:call-template name="checktermination-head"/>
        </body>
      </html>
    </exsl:document>
  </xsl:template>
  <xsl:template match="checkbegin[ancestor::preparation and not(ancestor::testcase)]|checkstartupinfo[ancestor::preparation and not(ancestor::testcase)]" mode="href-file">
    <xsl:apply-templates select="ancestor::preparation" mode="href-file"/>
  </xsl:template>
  <xsl:template match="checkbegin[ancestor::completion and not(ancestor::testcase)]|checkstartupinfo[ancestor::completion and not(ancestor::testcase)]" mode="href-file">
    <xsl:apply-templates select="ancestor::completion" mode="href-file"/>
  </xsl:template>
  <xsl:template match="checkbegin[ancestor::testsequence and not(ancestor::testcase)]|checkstartupinfo[ancestor::testsequence and not(ancestor::testcase)]" mode="href-file">
    <xsl:apply-templates select="ancestor::testsequence" mode="href-file"/>
  </xsl:template>
  <xsl:template match="checkbegin[ancestor::preparation and not(ancestor::testcase)]|checkstartupinfo[ancestor::testcase]" mode="href-file">
    <xsl:apply-templates select="ancestor::testcase" mode="href-file"/>
  </xsl:template>
  <xsl:template match="checkbegin|checkstartupinfo" mode="href-file">
    <xsl:value-of select="generate-id(..)"/>
    <xsl:text>chkbeg.html</xsl:text>
  </xsl:template>
  <xsl:template match="checkend|checkterminationinfo" mode="href-file">
    <xsl:value-of select="generate-id(..)"/>
    <xsl:text>chkend.html</xsl:text>
  </xsl:template>
  
  <xsl:template match="checkstatistic" mode="containing-file">
    <xsl:choose>
      <xsl:when test="parent::testmodule">Frame_Report.html</xsl:when>
      <xsl:when test="parent::testreport">Frame_Report.html</xsl:when>
      <xsl:otherwise>
        <xsl:apply-templates select=".." mode="href-file"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="testmodule|testcycle[parent::testmodule]" mode="failed-list">
    <xsl:param name="verdict"/>
    <xsl:apply-templates select="testcycle|testgroup|testcase" mode="failed-list">
      <xsl:with-param name="verdict" select="$verdict"/>
    </xsl:apply-templates>
  </xsl:template>
  <xsl:template match="testgroup" mode="failed-list">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:param name="verdict"/>
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    <xsl:variable name="nr">
      <xsl:call-template name="make-number-impl">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="node-nr" select="$start-nr + $counted-nodes"/>
      </xsl:call-template>
    </xsl:variable>
    <xsl:apply-templates select="testgroup|testsequence|testcase|testsequencelist|testcaselist" mode="failed-list">
      <xsl:with-param name="parent-nr" select="$nr"/>
      <xsl:with-param name="start-nr" select="0"/>
      <xsl:with-param name="verdict" select="$verdict"/> 
    </xsl:apply-templates>
  </xsl:template>
  <xsl:template match="testcase" mode="failed-list">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:param name="verdict"/>
    <xsl:if test="verdict[@result=$verdict] ">
      <xsl:call-template name="testcase-failed-list">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr"/>
      </xsl:call-template>
    </xsl:if>
  </xsl:template>
  <xsl:template name="testcase-failed-list">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    <xsl:variable name="hide-tc"> 
      <xsl:call-template name="hidetestcase"/>
    </xsl:variable>
    <tr>
      <td>
        <xsl:choose>
          <xsl:when test="not(boolean(number($hide-tc)))">
            <a>
              <xsl:attribute name="href">
                <xsl:apply-templates select="." mode="href-file"/>
              </xsl:attribute>
              <xsl:attribute name="target">Report</xsl:attribute>
              <xsl:attribute name="onclick">showTimestamp('<xsl:value-of select="@timestamp"/>')</xsl:attribute>
              <xsl:call-template name="show-number-impl">
                <xsl:with-param name="parent-nr" select="$parent-nr"/>
                <xsl:with-param name="start-nr" select="$start-nr + $counted-nodes"/>
              </xsl:call-template>
              <xsl:text> </xsl:text>
              <xsl:value-of select="title"/>
            </a>
          </xsl:when>
          <xsl:otherwise> 
            <xsl:call-template name="show-number-impl">
              <xsl:with-param name="parent-nr" select="$parent-nr"/>
              <xsl:with-param name="start-nr" select="$start-nr + $counted-nodes"/>
            </xsl:call-template>
            <xsl:text> </xsl:text>
            <xsl:value-of select="title"/>
          </xsl:otherwise>
        </xsl:choose>
      </td>
    </tr>
  </xsl:template>
  
  <xsl:template match="*" mode="link-up">
    <xsl:param name="rowspan"/>
    <xsl:call-template name="link-up">
      <xsl:with-param name="rowspan" select="$rowspan"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="testpattern" mode="link-up">
    <xsl:apply-templates select=".." mode="link-up"/>
  </xsl:template>
  <xsl:template match="preparation[parent::testcase]|completion[parent::testcase]" mode="link-up"/>
  <xsl:template match="preparation[parent::testsequence]|completion[parent::testsequence]" mode="link-up">
    <xsl:if test="$ShowSequenceAsGroup">
      <xsl:call-template name="link-up"/>
    </xsl:if>
  </xsl:template>
  <xsl:template match="preparation|completion|testcase" mode="link-up">
    <table>
      <tbody>
        <tr>
          <xsl:call-template name="link-up"/>
        </tr>
      </tbody>
    </table>
  </xsl:template>
  <xsl:template name="link-up">
    <xsl:param name="rowspan"/>
    <td class="UpCell">
      <xsl:if test="$rowspan">
        <xsl:attribute name="rowspan">
          <xsl:value-of select="$rowspan"/>
        </xsl:attribute>
      </xsl:if>
      <a>
        <xsl:attribute name="href">
          <xsl:apply-templates select=".." mode="href-file"/>
        </xsl:attribute>
        <xsl:text>Go up</xsl:text>
      </a>
    </td>
  </xsl:template>
  
  <xsl:template name="htmlFrameNavTree">
    <html>
      <head>
        <title>
          <xsl:value-of select="/*/title"/>
        </title>
        <link rel="stylesheet" type="text/css" href="../common_report_files/tree.css"/>
        <script type="text/javascript" src="../common_report_files/document.js"/>
        <script type="text/javascript" src="../common_report_files/tree.js"/>
        <xsl:call-template name="showtimestamp-script"/>
        <script type="text/javascript">
          var objTree = new jsTree;
          var testcycle;
          var testgroup;
          var testcase;
          
          //create the root
          <xsl:choose>
            <xsl:when test="/*/verdict/@result='error'">
              objTree.createRoot("../common_report_files/testmodul_error.gif", "<xsl:value-of select="/*/title"/>", true, "Frame_Report.html#TOP", "Report", "0");
            </xsl:when>
            <xsl:when test="/*/verdict/@result='fail'">
              objTree.createRoot("../common_report_files/testmodul_failed.gif", "<xsl:value-of select="/*/title"/>", true, "Frame_Report.html#TOP", "Report", "0");
            </xsl:when>
            <xsl:when test="/*/verdict/@result='inconclusive'">
              objTree.createRoot("../common_report_files/testmodul_inconclusive.gif", "<xsl:value-of select="/*/title"/>", true, "Frame_Report.html#TOP", "Report", "0");
            </xsl:when>
            <xsl:when test="/*/verdict/@result='pass'">
              objTree.createRoot("../common_report_files/testmodul_passed.gif", "<xsl:value-of select="/*/title"/>", true, "Frame_Report.html#TOP", "Report", "0");
            </xsl:when>
            <xsl:otherwise>
              objTree.createRoot("../common_report_files/testmodul_none.gif", "<xsl:value-of select="/*/title"/>", true, "Frame_Report.html#TOP", "Report", "0");
            </xsl:otherwise>
          </xsl:choose>
            
          //special childs for test information at the top of the report
          testcase = objTree.root.addChild("../common_report_files/info.gif", "General Test Information", true, "Frame_Report.html#GeneralTestInfo", "Report", "0");
          testcase = objTree.root.addChild("../common_report_files/info.gif", "Test Overview", true, "Frame_Report.html#TestOverview", "Report", "0");

          <!-- Add script calls to create the navigation tree with testgroups, testcases, etc. -->
          <xsl:apply-templates select="/*/testcycle|/*/testunit|/testmodule" mode="tree">
            <xsl:with-param name="parent-obj" select="'objTree.root'"/>
          </xsl:apply-templates>
          
          // Calls dialog to print ReportFrame
          function printReportFrame()
          {
            top.Report.print();
          }
          
          function init()
          {
            objTree.buildDOM();
          }
        </script>
      </head>
      <body style="background-color: rgb(220, 221, 222)" onLoad="init()">
        <xsl:attribute name="style">
          background-color: <xsl:value-of select="$NavBackgroundColor"/></xsl:attribute>
        <table>
          <tr>
            <td>
              <img src="../common_report_files/print.gif" alt="Print current Frame" onclick="printReportFrame()"/>
            </td>
          </tr>
        </table>
      </body>
    </html>
  </xsl:template>
  <xsl:template name="htmlFrameReport">
    <html>
      <head>
        <title>
          <xsl:value-of select="/*/title"/>
        </title>
        <xsl:call-template name="all-scripts"/>
        <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
      </head>
      <body>
        <xsl:call-template name="report-body"/>
      </body>
    </html>
  </xsl:template>
  <xsl:template name="htmlFrameFailedList">
    <html>
      <head>
        <title>
          <xsl:value-of select="/*/title"/>
          <xsl:text>Faulty test cases</xsl:text>
        </title>
        <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
        <xsl:call-template name="showtimestamp-script"/>
      </head>
      <body class="NavStyle">
        <div class="Heading4">Test cases with verdict none:</div>
        <table>
          <xsl:apply-templates select="/testmodule|/testreport" mode="failed-list">
            <xsl:with-param name="verdict" select="'none'"/>
          </xsl:apply-templates>
        </table>
        <div class="Heading4">Test cases with verdict inconclusive:</div>
        <table>
          <xsl:apply-templates select="/testmodule|/testreport" mode="failed-list">
            <xsl:with-param name="verdict" select="'inconclusive'"/>
          </xsl:apply-templates>
        </table>
        <div class="Heading4">Test cases with verdict fail:</div>
        <table>
          <xsl:apply-templates select="/testmodule|/testreport" mode="failed-list">
            <xsl:with-param name="verdict" select="'fail'"/>
          </xsl:apply-templates>
        </table>
        <div class="Heading4">Test cases with verdict error in Test System:</div>
        <table>
          <xsl:apply-templates select="/testmodule|/testreport" mode="failed-list">
            <xsl:with-param name="verdict" select="'error'"/>
          </xsl:apply-templates>
        </table>
      </body>
    </html>
  </xsl:template>
  <xsl:template name="htmlFrameLogFile">
    <html>
      <head>
        <title>Logfile Frame</title>
        <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
        <script type="text/javascript">
          function showTimestamp(timestamp) 
          {
            ExtNavigationApplet.showTimeStamp(timestamp);
          }
        </script>
      </head>
      <body>
        <!-- append non-empty log file entries -->
        <xsl:variable name="logfiles">
          <xsl:for-each select="//testlogfile">
            <xsl:if test="normalize-space(./@file)">
              <xsl:value-of select="translate(@file, '\', '/')"/>
              <xsl:text>|0|</xsl:text>
            </xsl:if>
          </xsl:for-each>
        </xsl:variable>
        <script src="../common_report_files/deployJava.js"/>
        <script>
          <xsl:text>var attributes = {code: 'ExtNavigationApplet.class', id:'ExtNavigationApplet', mayscript:'true', width: '100%', height: '100%'};</xsl:text>
          <xsl:text>var parameters = {jnlp_href: '../common_report_files/ExtNavigationApplet.jnlp', logfiles: '</xsl:text>
          <xsl:value-of select="$logfiles"/>
          <xsl:text>', docUrl: window.location.href};</xsl:text>
          <xsl:text>deployJava.runApplet(attributes, parameters, '1.6');</xsl:text>
        </script>
      </body>
    </html>
  </xsl:template>
  
  <!-- helper functions -->
  <xsl:template name="all-scripts">
    <xsl:call-template name="showtimestamp-script"/>
    <xsl:call-template name="expand-script"/>
  </xsl:template>
  <xsl:template name="showtimestamp-script">
    <script type="text/javascript">
      function showTimestamp(timestamp){top.LogFile.showTimestamp(timestamp);}
    </script>
  </xsl:template>
  <xsl:template name="aHrefImpl">
    <xsl:param name="externalID"/>
    <xsl:param name="externalFile"/>
    <xsl:param name="internalID"/>
    <xsl:param name="anchorText"/>
    
    <xsl:call-template name="aHref">
      <xsl:with-param name="externalID" select="$externalID"/>
      <xsl:with-param name="externalFile" select="$externalFile"/>
      <xsl:with-param name="internalID" select="$internalID"/>
      <xsl:with-param name="anchorText" select="$anchorText"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template name="showTimeStampImpl">
    <xsl:param name="timeStampValue"/>
    <a>
      <xsl:attribute name="href">javascript:showTimestamp('<xsl:value-of select="$timeStampValue"/>')</xsl:attribute>
      <xsl:value-of select="$timeStampValue"/>
    </a>
  </xsl:template>
  <xsl:template name="showUpperStatisticImpl">
    <xsl:param name="statisticNodeSet"/>
    <xsl:apply-templates select="$statisticNodeSet" mode="containing-file"/>
    <xsl:text>#</xsl:text>
    <xsl:apply-templates select="$statisticNodeSet" mode="checkstatistic-anchor"/>
  </xsl:template>
</xsl:stylesheet>
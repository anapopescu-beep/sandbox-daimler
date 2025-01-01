<?xml version="1.0" encoding="ISO-8859-1" standalone="yes" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:exsl="http://exslt.org/common" exclude-result-prefixes="exsl" extension-element-prefixes="exsl">
  
  <xsl:template match="testmodule[not(testcycle)]|testreport[not(testcycle)]" mode="results"/>
  <xsl:template match="testmodule|testreport" mode="results">
    <!-- Table with Test Results -->
    <xsl:apply-templates select="." mode="results-heading"/>
    <div class="Indentation">
      <table class="OverviewTable">
        <xsl:apply-templates select="self::testcycle" mode="overview"/>
        <xsl:apply-templates select="preparation" mode="overview"/>
        <xsl:apply-templates select="/testreport/testunit|testgroup|testcase|skipped" mode="overview"/>
        <xsl:apply-templates select="completion" mode="overview"/>
      </table>
    </div>
  </xsl:template>
  <xsl:template match="testmodule" mode="results-heading">
    <div class="Heading4">Test Case Results</div>
  </xsl:template>
  <xsl:template match="testmodule[testcycle]" mode="results-heading"/>
  
  <xsl:template match="testmodule" mode="information">
    <xsl:variable name="id-self">
      <xsl:if test="ancestor-or-self::testcycle">
        <xsl:call-template name="number-cycle"/>
      </xsl:if>
    </xsl:variable>
    <!-- Violations -->
    <xsl:if test="violation|descendant::testgroup/violation">
      <div id="{$DivPrefix}{$id-self}">
        <div class="Heading4">Violations occurred (not within test cases)</div>
        <div class="Indentation">
          <table class="OverviewTable">
            <xsl:apply-templates select="violation|descendant::testgroup/violation" mode="testmodule"/>
          </table>
        </div>
      </div>
    </xsl:if>
    
    <!-- Preparation/Completion section of test module -->
    <xsl:apply-templates select="preparation|completion" mode="testmodule">
      <xsl:with-param name="id" select="$id-self"/>
    </xsl:apply-templates>
    <!-- checkbegin/checkend outside a testcase -->
    <xsl:apply-templates select="(checkbegin|checkstartupinfo)[1]|(checkend|checkterminationinfo)[1]" mode="head">
      <xsl:with-param name="id" select="$id-self"/>
    </xsl:apply-templates>
    
    <xsl:apply-templates select="." mode="link-children"/>
    <xsl:apply-templates select="." mode="detailed">
      <xsl:with-param name="id" select="$id-self"/>
    </xsl:apply-templates>
  </xsl:template>
  <xsl:template match="testmodule" mode="title">
    <xsl:apply-templates select="." mode="heading-title"/>
  </xsl:template>
  <xsl:template match="testmodule" mode="heading">
    <table class="GroupHeadingTable">
      <tr>
        <td>
          <big class="Heading3">
            <xsl:apply-templates select="." mode="heading-title"/>
          </big>
        </td>
      </tr>
    </table>
  </xsl:template>
  <xsl:template match="testmodule" mode="heading-title">
    <xsl:value-of select="'Test Cycle 1'"/>
  </xsl:template>
  <xsl:template match="testmodule[testcycle]" mode="link-children">
    <xsl:call-template name="link-children"/>
    <xsl:apply-templates select="(checkbegin|checkstartupinfo)[1]|(checkend|checkterminationinfo)[1]" mode="file"/>
  </xsl:template>
  <xsl:template match="testmodule" mode="link-children">
    <div class="Indentation">
      <div class="Heading4">Contents</div>
      <div class="Indentation">
        <table class="OverviewTable">
        <tr>
          <td class="DefineCell" colspan="{$OverviewColumnCount}">
            <xsl:call-template name="a-href-ext">
              <xsl:with-param name="externalID" select="current()"/>
              <xsl:with-param name="externalFile" select="'cycleinfo.html'"/>
              <xsl:with-param name="anchorText">
                <xsl:apply-templates select="." mode="title"/>
              </xsl:with-param>
            </xsl:call-template>
          </td>
        </tr>
      </table>
      </div>
    </div>
  </xsl:template>
  <xsl:template match="testmodule" mode="href-file">
    <xsl:value-of select="generate-id(.)"/>
    <xsl:text>cycleinfo.html</xsl:text>
  </xsl:template>
  <xsl:template match="testmodule" mode="detailed">
    <xsl:variable name="href">
      <xsl:apply-templates select="." mode="href-file"/>
    </xsl:variable>
    <xsl:variable name="id-self">
      <xsl:if test="ancestor-or-self::testcycle">
        <xsl:call-template name="number-cycle"/>
      </xsl:if>
    </xsl:variable>
    
    <exsl:document href="{$href}" method="html" indent="yes" doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
      <html>
        <head>
          <title>
            <xsl:value-of select="@run"/>
          </title>
          <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
          <xsl:call-template name="expand-script"/>
        </head>
        <body>
          <xsl:apply-templates select="." mode="heading"/>
          <xsl:call-template name="test-results"/>
          <table class="SubHeadingTable">
            <tr>
              <xsl:apply-templates select="." mode="show-hide-multicycle"/>
              <td><div class="Heading2">Test Module Information</div></td>
            </tr>
          </table>
          
          <!-- Check statistics on test module level -->
          <xsl:if test="checkstatistic">
            <div id="{$DivPrefix}{$id-self}">
              <xsl:call-template name="checkstatistic-heading"/>
              <xsl:apply-templates select="checkstatistic" mode="report"/>
            </div>
          </xsl:if>
          
          <table class="SubHeadingTable">
            <tr>
              <td>
                <big class="Heading2">
                  <xsl:text>Test Case Details</xsl:text>
                </big>
              </td>
            </tr>
          </table>
    
          <xsl:apply-templates select="testcase|testgroup" mode="detailed">
            <xsl:with-param name="id">
              <xsl:call-template name="number-cycle"/>
            </xsl:with-param>
          </xsl:apply-templates>
        </body>
      </html>
    </exsl:document>
  </xsl:template>
  <xsl:template match="testmodule" mode="show-hide"/>
  <xsl:template match="testmodule" mode="show-hide-multicycle">
    <xsl:call-template name="show-hide-all">
      <xsl:with-param name="id" select="''"/>
    </xsl:call-template>
  </xsl:template>
   
  <xsl:template match="testcycle" mode="overview"/>
  <xsl:template match="testcycle" mode="information">
    <xsl:variable name="href">
      <xsl:apply-templates select="." mode="href-file"/>
    </xsl:variable>
    <xsl:variable name="id-self">
      <xsl:if test="ancestor-or-self::testcycle">
        <xsl:call-template name="number-cycle"/>
      </xsl:if>
    </xsl:variable>
    <exsl:document href="{$href}" method="html" indent="yes" doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
      <html>
        <head>
          <title>
            <xsl:value-of select="@run"/>
          </title>
          <link rel="stylesheet" type="text/css" href="extendedNavigation.css"/>
          <xsl:call-template name="expand-script"/>
        </head>
        <body>
          <xsl:apply-templates select="." mode="heading"/>
          <xsl:call-template name="test-results"/>
          
          <table class="SubHeadingTable">
            <tr>
              <xsl:apply-templates select="." mode="show-hide-multicycle"/>
              <td><div class="Heading2">Test Module Information</div></td>
            </tr>
          </table>
          
          <!-- Check statistics on test module level -->
          <xsl:if test="checkstatistic">
            <div id="{$DivPrefix}{$id-self}">
              <xsl:call-template name="checkstatistic-heading"/>
              <xsl:apply-templates select="checkstatistic" mode="report"/>
            </div>
          </xsl:if>
    
          <xsl:apply-templates select=".|testcase|testgroup" mode="detailed">
            <xsl:with-param name="id">
              <xsl:call-template name="number-cycle"/>
            </xsl:with-param>
          </xsl:apply-templates>
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
  <xsl:template match="testcycle" mode="show-hide-multicycle">
    <xsl:call-template name="show-hide-all">
      <xsl:with-param name="id" select="''"/>
    </xsl:call-template>
  </xsl:template>
  
  <xsl:template match="preparation|completion" mode="overview"/>  
  
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
          <xsl:call-template name="expand-script"/>
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
          <xsl:call-template name="expand-script"/>
        </head>
        <body>
          <xsl:call-template name="checktermination-head"/>
        </body>
      </html>
    </exsl:document>
  </xsl:template>
  
  <xsl:template match="checkbegin|checkstartupinfo" mode="href-file">
    <xsl:value-of select="generate-id(..)"/>
    <xsl:text>chkbeg.html</xsl:text>
  </xsl:template>
  <xsl:template match="checkend|checkterminationinfo" mode="href-file">
    <xsl:value-of select="generate-id(..)"/>
    <xsl:text>chkend.html</xsl:text>
  </xsl:template>
</xsl:stylesheet>
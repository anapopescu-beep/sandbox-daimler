<?xml version="1.0" encoding="ISO-8859-1" standalone="yes" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:variable name="RootFolder">
    <xsl:text>./</xsl:text>
  </xsl:variable>
  
  <!-- Template: Test Module Information section -->
  <xsl:template match="testmodule|testreport" mode="results">
    <!-- Table with Test Results -->
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
  <xsl:template match="testmodule" mode="information">
    <xsl:call-template name="testmodule-information"/>
  </xsl:template>
  <xsl:template match="testmodule" mode="show-hide">
    <xsl:call-template name="show-hide-all">
      <xsl:with-param name="id" select="''"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template name="testmodule-information">
    <xsl:variable name="id-self">
      <xsl:if test="ancestor-or-self::testcycle">
        <xsl:call-template name="number-cycle"/>
      </xsl:if>
    </xsl:variable>
    <!-- Check statistics on test module level -->
    <xsl:if test="checkstatistic">
      <div id="{$DivPrefix}{$id-self}">
        <xsl:call-template name="checkstatistic-heading"/>
        <xsl:apply-templates select="checkstatistic" mode="report"/>
      </div>
    </xsl:if>
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
  
  <xsl:template match="testmodule" mode="detailed">
    <xsl:param name="id"/>
    <!-- Test Case Details -->
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
      <xsl:with-param name="id" select="$id"/>
    </xsl:apply-templates>
  </xsl:template>
  
  <xsl:template match="testcycle" mode="information">
    <a name="{generate-id()}"/>
    <table class="SubHeadingTable">
      <tr>
        <xsl:apply-templates select="." mode="show-hide"/>
        <td>
          <div class="Heading2">
            <xsl:apply-templates select="." mode="heading-title"/>
          </div>
        </td>
      </tr>
    </table>
    <xsl:call-template name="testmodule-information"/>
  </xsl:template>
  <xsl:template match="testcycle[parent::testmodule]" mode="detailed">
    <xsl:param name="id"/>
    <!-- Test Case Details -->
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
      <xsl:with-param name="id" select="$id"/>
    </xsl:apply-templates>
  </xsl:template>
  <xsl:template match="testcycle" mode="show-hide">
    <xsl:call-template name="show-hide-all">
      <xsl:with-param name="id">
        <xsl:call-template name="number-cycle"/>
      </xsl:with-param>
    </xsl:call-template>
  </xsl:template>
  
  <xsl:template match="testgroup" mode="detailed">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:param name="id"/>
    <xsl:if test="descendant::testcase|descendant::testsequence|descendant::violation[ancestor::precondition or ancestor::preparation or ancestor::completion]|(descendant::teststep|descendant::checkstartupinfo|descendant::checkterminationinfo|descendant::command)[not(parent::testcase or parent::testsequence)]">
      <xsl:call-template name="testgroup-detailed">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr"/>
        <xsl:with-param name="id" select="$id"/>
      </xsl:call-template>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testgroup" mode="show-hide">
    <xsl:param name="id"/>
    <xsl:param name="rowspan"/>
    <xsl:call-template name="show-hide-all">
      <xsl:with-param name="id" select="$id"/>
      <xsl:with-param name="rowspan" select="$rowspan"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template name="testgroup-overview-impl">
    <a href="#{generate-id()}">
      <b>
        <xsl:value-of select="title"/>
      </b>
    </a>
  </xsl:template>
  <xsl:template name="testgroup-detailed-impl">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:param name="id"/>
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    
    <!-- Preparation section of test group -->
    <xsl:apply-templates select="preparation" mode="testgroup">
      <xsl:with-param name="id" select="concat($id, 'p')"/>
    </xsl:apply-templates>
    
    <!-- checkbegin not in a test case  -->
    <xsl:apply-templates select="(checkbegin|checkstartupinfo)[1]" mode="head">
      <xsl:with-param name="id" select="$id"/>
    </xsl:apply-templates>
    
    <!-- Content (test cases, nested test groups) of test group -->
    <xsl:apply-templates select="testgroup|testfixture|testsequence|testcase|testsequencelist|testcaselist" mode="detailed">
      <xsl:with-param name="parent-nr" select="$parent-nr"/>
      <xsl:with-param name="start-nr" select="0"/>
      <xsl:with-param name="id" select="$id"/>
    </xsl:apply-templates>
    
    <!-- checkend not in a test case  -->
    <xsl:apply-templates select="(checkend|checkterminationinfo)[1]" mode="head">
      <xsl:with-param name="id" select="$id"/>
    </xsl:apply-templates>
    
    <!-- Completion section of test group -->
    <xsl:apply-templates select="completion" mode="testgroup">
      <xsl:with-param name="id" select="concat($id, 'c')"/>
    </xsl:apply-templates>
  </xsl:template>
  
  <xsl:template match="testcase" mode="detailed">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:param name="id"/>
    <xsl:variable name="hide-tc">
      <xsl:call-template name="hidetestcase"/>
    </xsl:variable>
    <xsl:variable name="show-tc" select="not(boolean(number($hide-tc)))"/>
    <xsl:if test="$show-tc">
      <xsl:call-template name="testcase-detailed">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr"/>
        <xsl:with-param name="id" select="$id"/>
      </xsl:call-template>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcase[./precondition/precondend[@fulfilled='false']]" mode="detailed">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:param name="id"/>
    <xsl:if test="$ShowFailedPreconditions">
      <xsl:call-template name="testcase-detailed">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr"/>
        <xsl:with-param name="id" select="$id"/>
      </xsl:call-template>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcase" mode="show-hide">
    <xsl:param name="id"/>
    <xsl:call-template name="show-hide-all">
      <xsl:with-param name="id" select="$id"/>
    </xsl:call-template>
  </xsl:template>
  
  <xsl:template match="preparation|completion" mode="overview"/>
  <xsl:template match="preparation|completion" mode="testmodule">
    <xsl:param name="id"/>
    <xsl:call-template name="preparation-completion">
      <xsl:with-param name="containerText" select="'Test Module'"/>
      <xsl:with-param name="withBeginEnd" select="true()"/>
      <xsl:with-param name="id" select="concat($id, substring(name(.), 1, 1))"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="preparation|completion" mode="testgroup-overview"/>
  <xsl:template match="preparation|completion" mode="testgroup">
    <xsl:param name="id"/>
    <xsl:call-template name="preparation-completion">
      <xsl:with-param name="containerText" select="'Test Group'"/>
      <xsl:with-param name="id" select="$id"/>
    </xsl:call-template>
  </xsl:template>
  
  <xsl:template match="checkbegin|checkstartupinfo" mode="href-file"/>
  
  <xsl:template match="/*" mode="report-end">
    <!-- Mark for the end of the report -->
    <table class="SubHeadingTable">
      <tr>
        <td>
          <div class="Heading2">
            <xsl:text>End of Report</xsl:text>
          </div>
        </td>
      </tr>
    </table>
  </xsl:template>
  <xsl:template match="*" mode="end">
    <table class="GroupEndTable">
      <tr>
        <td>
          <xsl:text>End of </xsl:text>
          <xsl:apply-templates select="." mode="name"/>
          <xsl:text>: </xsl:text>
          <xsl:value-of select="title"/>
        </td>
      </tr>
    </table>
  </xsl:template>
  <xsl:template match="*" mode="link-up"/>
  <xsl:template match="*" mode="link-children"/>
  
  <xsl:template name="aHrefImpl">
    <xsl:param name="externalID"/>
    <xsl:param name="internalID"/>
    <xsl:param name="anchorText"/>
    <xsl:param name="onclick"/>
    <xsl:choose>
      <xsl:when test="string-length($internalID) = 0">
        <xsl:call-template name="aHref">
          <xsl:with-param name="internalID" select="$externalID"/>
          <xsl:with-param name="anchorText" select="$anchorText"/>
          <xsl:with-param name="onclick" select="$onclick"/>
        </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
        <xsl:call-template name="aHref">
          <xsl:with-param name="internalID" select="$internalID"/>
          <xsl:with-param name="anchorText" select="$anchorText"/>
          <xsl:with-param name="onclick" select="$onclick"/>
        </xsl:call-template>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  <xsl:template name="showTimeStampImpl">
    <xsl:param name="timeStampValue"/>
    <xsl:value-of select="$timeStampValue"/>
  </xsl:template>
  <xsl:template name="showUpperStatisticImpl">
    <xsl:param name="statisticNodeSet"/>
    <xsl:text>#</xsl:text>
    <xsl:apply-templates select="$statisticNodeSet" mode="checkstatistic-anchor"/>
  </xsl:template>
  <xsl:template name="linkFrameImpl"/>
</xsl:stylesheet>
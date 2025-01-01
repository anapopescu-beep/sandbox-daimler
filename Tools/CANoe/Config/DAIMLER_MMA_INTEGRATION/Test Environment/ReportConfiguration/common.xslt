<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:key name="csSetupNodes" match="checkstatistic[@seq]" use="@id"/>
  <xsl:key name="checkBeginNodes" match="checkbegin" use="@id"/>

  <xsl:template name="report-body">
    <a name="TOP"/>
    <!-- Uncomment and adjust the following line to add a logo in the right upper corner. -->
    <!--<p align="right"><img src="vector_logo.bmp" alt="Vector Informatik" border="0" /></p> -->
    <!-- Report Heading -->
    <table class="HeadingTable">
      <tr>
        <td>
          <big class="Heading1">
            <xsl:text>Report: </xsl:text>
            <xsl:value-of select="/*/title" />
          </big>
        </td>
      </tr>
    </table>

    <!-- Overall Result -->
    <center>
      <table class="OverallResultTable">
        <tr>
          <td>
            <xsl:choose>
              <xsl:when test="/*/verdict/@result='none'">
                <xsl:attribute name="class">NoneResult</xsl:attribute>
                <xsl:text>Test finished without verdict</xsl:text>
              </xsl:when>
              <xsl:when test="/*/verdict/@result='pass'">
                <xsl:attribute name="class">PositiveResult</xsl:attribute>
                <xsl:text>Test passed</xsl:text>
              </xsl:when>
              <xsl:when test="/*/verdict/@result='inconclusive'">
                <xsl:attribute name="class">InconclusiveResult</xsl:attribute>
                <xsl:text>Test inconclusive</xsl:text>
              </xsl:when>
              <xsl:when test="/*/verdict/@result='fail'">
                <xsl:attribute name="class">NegativeResult</xsl:attribute>
                <xsl:text>Test failed</xsl:text>
              </xsl:when>
              <xsl:when test="/*/verdict/@result='error'">
                <xsl:attribute name="class">ErrorResult</xsl:attribute>
                <xsl:text>Test finished with error in test system</xsl:text>
              </xsl:when>
            </xsl:choose>
          </td>
        </tr>
      </table>
    </center>

    <!-- Section: General Test Information -->
    <a name="GeneralTestInfo"/>
    <table class="SubHeadingTable">
      <tr>
        <td>
          <div class="Heading2"><xsl:text>General Test Information</xsl:text></div>
        </td>
      </tr>
    </table>

    <!-- Test Report Description -->
    <xsl:apply-templates select="/*/description" mode="paragraph"/>

    <!-- General Test Information Section -->
    <div class="Indentation">
      <!-- SUT information -->
      <xsl:if test="/*/sut">
        <xsl:apply-templates select="/*/sut"/>
      </xsl:if>

      <!-- Test Engineer -->
      <xsl:if test="/*/engineer">
        <xsl:apply-templates select="/*/engineer"/>
      </xsl:if>

      <!-- Test Setup -->
      <xsl:if test="/*/testsetup">
        <xsl:apply-templates select="/*/testsetup"/>
      </xsl:if>

      <!-- Hardware -->
      <xsl:if test="/*/hardware">
        <xsl:apply-templates select="/*/hardware"/>
      </xsl:if>

      <!-- Module Details -->
      <xsl:for-each select="//moduledetails">
        <xsl:if test="title">
          <div class="Heading4"><xsl:value-of select="title" /></div>
        </xsl:if>
        <div class="Indentation">
          <xsl:apply-templates select="image"/>
        </div>
      </xsl:for-each>

      <!-- Logging files -->
      <xsl:apply-templates select="/*/testlogfiles"/>

      <!-- External references -->
      <xsl:apply-templates select="/*/externalref"/>

      <!-- Miscellaneous Information-->
      <xsl:apply-templates select="/*/miscinfo"/>

      <!-- Extended Information -->
      <xsl:apply-templates select="/*/extendedinfo"/>

    </div> <!-- End of General Test Information section -->

    <!-- Test Overview -->
    <a name="TestOverview"/>
    <table class="SubHeadingTable">
      <tr>
        <td>
          <div class="Heading2"><xsl:text>Test Overview</xsl:text></div>
        </td>
      </tr>
    </table>

    <div class="Indentation">
      <!-- Start and end time of test -->
      <xsl:call-template name="beginend">
        <xsl:with-param name="what">Test</xsl:with-param>
        <xsl:with-param name="nodeset" select="/*|/*/verdict"/>
      </xsl:call-template>

      <!-- Statistics -->
      <div class="Heading4">Statistics</div>
      <div class="Indentation">
        <table class="OverviewTable">
          <xsl:apply-templates select="." mode="statistics"/>
        </table>
      </div>

      <xsl:apply-templates select="." mode="statistics-warnings"/>

      <!-- Test Results Table -->
      <xsl:apply-templates select="/testmodule|/testreport" mode="results"/>
    </div>

    <!-- Test Module/Configuration Information section -->
    <a name="TestModuleInfo"/>
    <xsl:apply-templates select="." mode="report-heading"/>

    <!-- Check cycles of execution -->
    <xsl:choose>
      <xsl:when test="/*/testcycle">
        <xsl:apply-templates select="/*/testcycle" mode="information"/>
        <xsl:apply-templates select="/*" mode="link-children"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-templates select="/testreport|/testmodule" mode="information"/>
      </xsl:otherwise>
    </xsl:choose>
    <xsl:apply-templates select="." mode="report-end"/>
  </xsl:template>

  <xsl:template name="test-results">
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

  <xsl:template match="testmodule" mode="report-heading">
    <table class="SubHeadingTable">
      <tr>
        <xsl:apply-templates select="." mode="show-hide"/>
        <td><div class="Heading2">Test Module Information</div></td>
      </tr>
    </table>
  </xsl:template>
  <xsl:template match="testmodule|testcycle" mode="results-heading">
    <div class="Heading4">Test Case Results</div>
  </xsl:template>
  <xsl:template match="testmodule" mode="statistics">
    <xsl:variable name="nTestcases"><xsl:value-of select="count(//testcase)+count(//skipped|//skippedcase)"/></xsl:variable>
    <tr>
      <td class="DefineCell">Overall number of test cases </td>
      <td class="NumberCell" width="60"><xsl:value-of select="$nTestcases"/></td>
      <td class="DefaultCell"/>
    </tr>
    <xsl:if test="$nTestcases > 0">
      <xsl:variable name="nExecTestcases"><xsl:value-of select="count(//testcase)"/></xsl:variable>
      <tr>
        <td class="DefineCell">Executed test cases </td>
        <td class="NumberCell"><xsl:value-of select="$nExecTestcases" /></td>
        <td class="DefaultCell">
          <xsl:variable name="execPercentage"><xsl:value-of select="$nExecTestcases div $nTestcases"/></xsl:variable>
          <xsl:choose>
            <xsl:when test="$execPercentage > 0.0 and 0.01 > $execPercentage"><xsl:text>1%</xsl:text></xsl:when>
            <xsl:when test="1.0 > $execPercentage and $execPercentage > 0.99"><xsl:text>99%</xsl:text></xsl:when>
            <xsl:otherwise><xsl:value-of select="format-number($execPercentage, '##0%')"/></xsl:otherwise>
          </xsl:choose>
          <xsl:text> of all test cases</xsl:text>
        </td>
      </tr>
      <tr>
        <td class="DefineCell">Not executed test cases </td>
        <td class="NumberCell"><xsl:value-of select="count(//skipped|//skippedcase)" /></td>
        <td class="DefaultCell">
          <xsl:variable name="skipPercentage"><xsl:value-of select="count(//skipped|//skippedcase) div $nTestcases"/></xsl:variable>
          <xsl:choose>
            <xsl:when test="$skipPercentage > 0.0 and 0.01 > $skipPercentage"><xsl:text>1%</xsl:text></xsl:when>
            <xsl:when test="1.0 > $skipPercentage and $skipPercentage > 0.99"><xsl:text>99%</xsl:text></xsl:when>
            <xsl:otherwise><xsl:value-of select="format-number($skipPercentage, '##0%')"/></xsl:otherwise>
          </xsl:choose>
          <xsl:text> of all test cases</xsl:text>
        </td>
      </tr>
      <xsl:if test="$nExecTestcases > 0">
        <xsl:variable name="tc-pass" select="count(//testcase/verdict[@result='pass'])"/>
        <xsl:variable name="tc-fail" select="count(//testcase/verdict[@result='fail'])"/>
        <xsl:variable name="tc-incon" select="count(//testcase/verdict[@result='inconclusive'])"/>
        <xsl:variable name="tc-error" select="count(//testcase/verdict[@result='error'])"/>
        <xsl:variable name="tc-none" select="count(//testcase/verdict[@result='none'])"/>
        <tr>
          <xsl:variable name="PositiveResultClass">
            <xsl:choose>
              <xsl:when test="$tc-pass != 0">NumberCellPositiveResult</xsl:when>
              <xsl:otherwise>NumberCell</xsl:otherwise>
            </xsl:choose>
          </xsl:variable>
          <td class="DefineCell">Test cases passed </td>
          <td class='{$PositiveResultClass}'><xsl:value-of select="$tc-pass" /></td>
          <td class='{$PositiveResultClass}'>
            <xsl:variable name="passedPercentage"><xsl:value-of select="$tc-pass div $nExecTestcases"/></xsl:variable>
            <xsl:choose>
              <xsl:when test="$passedPercentage > 0.0 and 0.01 > $passedPercentage"><xsl:text>1%</xsl:text></xsl:when>
              <xsl:when test="1.0 > $passedPercentage and $passedPercentage > 0.99"><xsl:text>99%</xsl:text></xsl:when>
              <xsl:otherwise><xsl:value-of select="format-number($passedPercentage, '##0%')"/></xsl:otherwise>
            </xsl:choose>
            <xsl:text> of executed test cases</xsl:text>
          </td>
        </tr>
        <tr>
          <xsl:variable name="ResultClass">
            <xsl:choose>
              <xsl:when test="$tc-fail != 0">NumberCellNegativeResult</xsl:when>
              <xsl:otherwise>NumberCell</xsl:otherwise>
            </xsl:choose>
          </xsl:variable>
          <td class="DefineCell">Test cases failed </td>
          <td class='{$ResultClass}'><xsl:value-of select="$tc-fail" /></td>
          <td class='{$ResultClass}'>
            <xsl:variable name="failedPercentage"><xsl:value-of select="$tc-fail div $nExecTestcases"/></xsl:variable>
            <xsl:choose>
              <xsl:when test="$failedPercentage > 0.0 and 0.01 > $failedPercentage"><xsl:text>1%</xsl:text></xsl:when>
              <xsl:when test="1.0 > $failedPercentage and $failedPercentage > 0.99"><xsl:text>99%</xsl:text></xsl:when>
              <xsl:otherwise><xsl:value-of select="format-number($failedPercentage, '##0%')"/></xsl:otherwise>
            </xsl:choose>
            <xsl:text> of executed test cases</xsl:text>
          </td>
        </tr>
        <xsl:if test="$tc-incon > 0">
          <tr>
            <xsl:variable name="InconclusiveResultClass">
              <xsl:choose>
                <xsl:when test="$tc-incon>0">NumberCellInconclusiveResult</xsl:when>
                <xsl:otherwise>NumberCell</xsl:otherwise>
              </xsl:choose>
            </xsl:variable>
            <td class="DefineCell">Test cases inconclusive</td>
            <td class='{$InconclusiveResultClass}'><xsl:value-of select="$tc-incon"/></td>
            <td class='{$InconclusiveResultClass}'>
              <xsl:variable name="inconPercentage"><xsl:value-of select="$tc-incon div $nExecTestcases"/></xsl:variable>
              <xsl:choose>
                <xsl:when test="$inconPercentage > 0.0 and 0.01 > $inconPercentage"><xsl:text>1%</xsl:text></xsl:when>
                <xsl:when test="1.0 > $inconPercentage and $inconPercentage > 0.99"><xsl:text>99%</xsl:text></xsl:when>
                <xsl:otherwise><xsl:value-of select="format-number($inconPercentage, '##0%')"/></xsl:otherwise>
              </xsl:choose>
              <xsl:text> of executed test cases</xsl:text>
            </td>
          </tr>
        </xsl:if>
        <xsl:if test="$tc-error > 0">
          <tr>
            <xsl:variable name="ErrorResultClass">
              <xsl:choose>
                <xsl:when test="$tc-error!=0">NumberCellErrorResult</xsl:when>
                <xsl:otherwise>NumberCell</xsl:otherwise>
              </xsl:choose>
            </xsl:variable>
            <td class="DefineCell">Test cases with error in test system</td>
            <td class='{$ErrorResultClass}'><xsl:value-of select="$tc-error" /></td>
            <td class='{$ErrorResultClass}'>
              <xsl:variable name="errorPercentage"><xsl:value-of select="$tc-error div $nExecTestcases"/></xsl:variable>
              <xsl:choose>
                <xsl:when test="$errorPercentage > 0.0 and 0.01 > $errorPercentage"><xsl:text>1%</xsl:text></xsl:when>
                <xsl:when test="1.0 > $errorPercentage and $errorPercentage > 0.99"><xsl:text>99%</xsl:text></xsl:when>
                <xsl:otherwise><xsl:value-of select="format-number($errorPercentage, '##0%')"/></xsl:otherwise>
              </xsl:choose>
              <xsl:text> of executed test cases</xsl:text>
            </td>
          </tr>
        </xsl:if>
        <xsl:if test="$tc-none > 0">
          <tr>
            <xsl:variable name="NoneResultClass">
              <xsl:choose>
                <xsl:when test="$tc-none != 0">NumberCellNoneResult</xsl:when>
                <xsl:otherwise>NumberCell</xsl:otherwise>
              </xsl:choose>
            </xsl:variable>
            <td class="DefineCell">Test cases without verdict</td>
            <td class='{$NoneResultClass}'><xsl:value-of select="$tc-none" /></td>
            <td class='{$NoneResultClass}'>
              <xsl:variable name="nonePercentage"><xsl:value-of select="$tc-none div $nExecTestcases"/></xsl:variable>
              <xsl:choose>
                <xsl:when test="$nonePercentage > 0.0 and 0.01 > $nonePercentage"><xsl:text>1%</xsl:text></xsl:when>
                <xsl:when test="1.0 > $nonePercentage and $nonePercentage > 0.99"><xsl:text>99%</xsl:text></xsl:when>
                <xsl:otherwise><xsl:value-of select="format-number($nonePercentage, '##0%')"/></xsl:otherwise>
              </xsl:choose>
              <xsl:text> of executed test cases</xsl:text>
            </td>
          </tr>
        </xsl:if>
      </xsl:if>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testreport|testmodule" mode="statistics-warnings">
    <xsl:if test="$ShowWarningMessage">
      <div class="Indentation">Warnings occured during test execution.</div>
    </xsl:if>
  </xsl:template>

  <xsl:template match="testcycle" mode="heading">
    <table class="GroupHeadingTable">
      <tr>
        <xsl:apply-templates select="." mode="link-up"/>
        <td>
          <big class="Heading3">
            <xsl:apply-templates select="." mode="heading-title"/>
          </big>
        </td>
      </tr>
    </table>
  </xsl:template>
  <xsl:template match="testcycle[parent::testmodule]" mode="heading-title">
    <xsl:value-of select="concat('Test Cycle ', @run)"/>
  </xsl:template>

  <!-- Template: Precondition section -->
  <xsl:template match="precondition">
    <xsl:param name="id"/>
    <xsl:if test="teststep">
      <table class="ResultTable">
        <xsl:call-template name="teststep-header"/>
        <xsl:apply-templates select="teststep" mode="testcase">
          <xsl:with-param name="id" select="$id"/>
        </xsl:apply-templates>
      </table>
    </xsl:if>
  </xsl:template>
  <!-- Template: Preparation|Completion ignored when empty -->
  <xsl:template match="preparation[count(child::*)=1]|completion[count(child::*)=1]" priority="2.5"/>
  <xsl:template match="preparation[count(child::*)=1]|completion[count(child::*)=1]" priority="2.5" mode="testgroup"/>
  <xsl:template match="preparation[count(child::*)=1]|completion[count(child::*)=1]" priority="2.5" mode="testmodule"/>

  <!-- Template: Preparation|Completion section -->
  <xsl:template match="preparation[parent::testcase]|completion[parent::testcase]">
    <xsl:param name="id"/>
    <xsl:call-template name="preparation-completion">
      <xsl:with-param name="containerText" select="'Test Case'"/>
      <xsl:with-param name="id" select="$id"/>
    </xsl:call-template>
  </xsl:template>
  <!-- Template: Preparation|Completion section -->
  <xsl:template name="preparation-completion">
    <xsl:param name="containerText"/>
    <xsl:param name="withBeginEnd" select="false()"/>
    <xsl:param name="id"/>

    <xsl:apply-templates select="." mode="link-up"/>

    <div id="{$DivPrefix}{$id}">
      <table class="TestGroupHeadingBackground">
        <tr>
          <td>
            <big class="Heading3">
              <xsl:apply-templates select="." mode="name-of"/>
              <xsl:value-of select="$containerText"/>
            </big>
          </td>
        </tr>
      </table>
      <div class="Indentation">
        <xsl:if test="$withBeginEnd">
          <xsl:apply-templates select="." mode="begin-end"/>
        </xsl:if>

        <!-- expand/collapse links -->
        <xsl:if test="descendant::tabularinfo">
          <xsl:apply-templates select="." mode="tabularinfo">
            <xsl:with-param name="id" select="$id"/>
          </xsl:apply-templates>
        </xsl:if>

        <!-- Now show the preparation operations -->
        <xsl:if test="sysvardef">
          <div class="Heading5">System Variables:</div>
          <div class="Indentation">
            <table class="OverviewTable">
              <tr>
                <th class="TableHeadingCell">Name</th>
                <th class="TableHeadingCell">Type</th>
                <th class="TableHeadingCell">Value</th>
                <th class="TableHeadingCell">Min</th>
                <th class="TableHeadingCell">Max</th>
                <th class="TableHeadingCell">Value Table</th>
              </tr>
              <xsl:apply-templates select="sysvardef" />
            </table>
          </div>
        </xsl:if>
        <xsl:if test="vardef">
          <xsl:call-template name="vardef-table"/>
        </xsl:if>
        <xsl:if test="testpattern|teststep|comment|details|violation|command|checkbegin|checkstartupinfo|checkend|checkterminationinfo">
          <table class="ResultTable">
            <xsl:call-template name="teststep-header"/>
            <xsl:apply-templates select="testpattern|teststep|comment|details|violation|command|checkbegin|checkstartupinfo|checkend|checkterminationinfo">
              <xsl:with-param name="id" select="$id"/>
            </xsl:apply-templates>
          </table>
        </xsl:if>
      </div>
    </div>
  </xsl:template>
  <xsl:template match="preparation" mode="begin-end">
    <xsl:call-template name="beginend">
      <xsl:with-param name="what">Preparation</xsl:with-param>
      <xsl:with-param name="nodeset" select=".|prepend"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="completion" mode="begin-end">
    <xsl:call-template name="beginend">
      <xsl:with-param name="what">Completion</xsl:with-param>
      <xsl:with-param name="nodeset" select=".|compend"/>
    </xsl:call-template>
  </xsl:template>

  <!-- Template: Overview of test groups -->
  <xsl:template match="testgroup" mode="overview">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:call-template name="testgroup-overview">
      <xsl:with-param name="parent-nr" select="$parent-nr"/>
      <xsl:with-param name="start-nr" select="$start-nr"/>
    </xsl:call-template>
  </xsl:template>
  <!-- Template: Controls the overview of testgroup with failed precondition -->
  <xsl:template match="testgroup[./precondition/precondend[@fulfilled='false']]" mode="overview">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:if test="$ShowFailedPreconditions">
      <xsl:call-template name="testgroup-overview">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr"/>
      </xsl:call-template>
    </xsl:if>
  </xsl:template>
  <xsl:template name="testgroup-overview">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    <xsl:variable name="test-items-count">
      <xsl:value-of select="count(descendant::testcase|descendant::testsequence|descendant::testcaselist|descendant::testsequencelist)"/>
    </xsl:variable>
    <tr>
      <xsl:if test="$ShowAutomaticTestModuleNumbering=true()">
        <td class="DefineCell">
          <b>
            <xsl:call-template name="show-number-impl">
              <xsl:with-param name="parent-nr" select="$parent-nr"/>
              <xsl:with-param name="start-nr" select="$start-nr + $counted-nodes"/>
            </xsl:call-template>
          </b>
        </td>
      </xsl:if>
      <xsl:if test="$StructureIdents=true()">
        <td class="DefineCell">
          <b>
            <xsl:value-of select="ident" />
          </b>
        </td>
      </xsl:if>
      <xsl:if test="$test-items-count=0">
        <td class="DefineCell">
          <b>
            <xsl:value-of select="title"/>
          </b>
        </td>
        <td class="DefineCell">
          <xsl:text>not executed</xsl:text>
        </td>
        <xsl:if test="$ShowWarningsInStatistics">
          <td class="DefaultCell"/>
        </xsl:if>
        <xsl:if test="$EnableSpecialVerdictInfo=true()">
          <td class="DefaultCell"/>
        </xsl:if>
      </xsl:if>
      <xsl:if test="$test-items-count>0">
        <td class="DefineCell">
          <xsl:if test="/testmodule">
            <xsl:attribute name="colspan">
              <xsl:if test="not($ShowWarningsInStatistics)">2</xsl:if>
              <xsl:if test="$ShowWarningsInStatistics">3</xsl:if>
            </xsl:attribute>
          </xsl:if>
          <xsl:call-template name="testgroup-overview-impl"/>
        </td>
        <xsl:if test="not(/testmodule)">
          <td style="padding:0px;" class="DefineCell">
            <xsl:call-template name="testcase-statistic"/>
          </td>
        </xsl:if>
        <xsl:if test="$EnableSpecialVerdictInfo=true()">
          <td class="DefineCell">
            <xsl:if test="miscinfo/title[text()='Verdict Information']">
              <xsl:value-of select="miscinfo/title[text()='Verdict Information']/../info[position()=1]/description"/>
            </xsl:if>
          </td>
        </xsl:if>
      </xsl:if>
    </tr>

    <xsl:if test="$test-items-count>0">
      <xsl:variable name="nr">
        <xsl:call-template name="make-number-impl">
          <xsl:with-param name="parent-nr" select="$parent-nr"/>
          <xsl:with-param name="node-nr" select="$start-nr + $counted-nodes"/>
        </xsl:call-template>
      </xsl:variable>
      <xsl:apply-templates select="testgroup|testfixture|testsequence|testcase|testsequencelist|testcaselist|skippedcase|skippedgroup|skippedfixture|skippedsequence|skipped|skippedtestsequencelist|skippedtestcaselist" mode="overview">
        <xsl:with-param name="parent-nr" select="$nr"/>
        <xsl:with-param name="start-nr" select="0"/>
      </xsl:apply-templates>
    </xsl:if>
  </xsl:template>

  <xsl:template name="testcase-statistic">
    <xsl:param name="is-overview" select="true()"/>
    <xsl:variable name="tc-all" select="descendant::testcase"/>

    <xsl:variable name="tc-none" select="count($tc-all/verdict[@result='none'])"/>
    <xsl:variable name="tc-pass" select="count($tc-all/verdict[@result='pass'])"/>
    <xsl:variable name="tc-fail" select="count($tc-all/verdict[@result='fail'])"/>
    <xsl:variable name="tc-incon" select="count($tc-all/verdict[@result='inconclusive'])"/>
    <xsl:variable name="tc-error" select="count($tc-all/verdict[@result='error'])"/>
    <xsl:variable name="tc-count" select="count($tc-all)"/>
    <xsl:variable name="tc-none-proc" select="$tc-none * 100 div $tc-count"/>
    <xsl:variable name="tc-pass-proc" select="$tc-pass * 100 div $tc-count"/>
    <xsl:variable name="tc-fail-proc" select="$tc-fail * 100 div $tc-count"/>
    <xsl:variable name="tc-incon-proc" select="$tc-incon * 100 div $tc-count"/>
    <xsl:variable name="tc-error-proc" select="$tc-error * 100 div $tc-count"/>

    <xsl:choose>
      <xsl:when test="$tc-count = 0">
        <xsl:attribute name="colspan">
          <xsl:if test="not($ShowWarningsInStatistics)">2</xsl:if>
          <xsl:if test="$ShowWarningsInStatistics">3</xsl:if>
        </xsl:attribute>
      </xsl:when>
      <xsl:otherwise>
        <table class="OverviewResultTable">
          <tr>
            <xsl:if test="$tc-none > 0">
              <td class="NoneResultCell" width="{format-number($tc-none-proc, '##0.##')}%">
                <xsl:value-of select="$tc-none"/>
              </td>
            </xsl:if>
            <xsl:if test="$tc-pass > 0">
              <td class="PositiveResultCell" width="{format-number($tc-pass-proc, '##0.##')}%">
                <xsl:value-of select="$tc-pass"/>
              </td>
            </xsl:if>
            <xsl:if test="$tc-incon > 0">
              <td class="InconclusiveResultCell" width="{format-number($tc-incon-proc, '##0.##')}%">
                <xsl:value-of select="$tc-incon"/>
              </td>
            </xsl:if>
            <xsl:if test="$tc-fail > 0">
              <td class="NegativeResultCell" width="{format-number($tc-fail-proc, '##0.##')}%">
                <xsl:value-of select="$tc-fail"/>
              </td>
            </xsl:if>
            <xsl:if test="$tc-error > 0">
              <td class="ErrorResultCell" width="{format-number($tc-error-proc, '##0.##')}%">
                <xsl:value-of select="$tc-error"/>
              </td>
            </xsl:if>
          </tr>
        </table>
        <xsl:if test="$is-overview and $ShowWarningsInStatistics">
          <td class="DefineCell"></td>
        </xsl:if>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <!-- Template: Details of test groups -->
  <xsl:template name="testgroup-detailed">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:param name="id"/>
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    <xsl:variable name="id-self">
      <xsl:if test="string-length($id) > 0">
        <xsl:value-of select="$id"/>
        <xsl:text>.</xsl:text>
      </xsl:if>
      <xsl:value-of select="$start-nr + $counted-nodes + 1"/>
    </xsl:variable>
    <xsl:apply-templates select="." mode="heading">
      <xsl:with-param name="parent-nr" select="$parent-nr"/>
      <xsl:with-param name="start-nr" select="$start-nr + $counted-nodes"/>
      <xsl:with-param name="id" select="$id-self"/>
    </xsl:apply-templates>

    <div id="{$DivPrefix}{$id-self}">
      <xsl:if test="xinfo|info">
        <div class="Indentation">
          <table>
            <xsl:for-each select="xinfo|info">
              <tr>
                <td class="CellNoColor"><xsl:value-of select="name" /><xsl:text>: </xsl:text></td>
                <td class="CellNoColor">
                  <xsl:call-template name="replacelinebreak">
                    <xsl:with-param name="srcnode">
                      <xsl:value-of select="description" />
                    </xsl:with-param>
                  </xsl:call-template>
                </td>
              </tr>
            </xsl:for-each>
          </table>
        </div>
      </xsl:if>

      <!-- Testgroup description-->
      <xsl:apply-templates select="description" mode="paragraph"/>

      <div class="Indentation">
        <!-- External references -->
        <xsl:apply-templates select="externalref"/>

        <!-- Test case miscellaneous information -->
        <xsl:apply-templates select="miscinfo"/>

        <!-- Test case extended information -->
        <xsl:apply-templates select="extendedinfo"/>

        <!-- Check statistics of test group -->
        <xsl:if test="checkstatistic">
          <div class="Heading4">
            <xsl:text>Test Group Check Statistics</xsl:text>
          </div>
          <xsl:apply-templates select="checkstatistic" mode="report"/>
        </xsl:if>
      </div>

      <!-- Precondition section of test group -->
      <xsl:if test="precondition">
        <table class="TestGroupHeadingBackground">
          <tr>
            <td>
              <big class="Heading3">Precondition of Test Group</big>
            </td>
          </tr>
        </table>
        <div class="Indentation">
          <xsl:apply-templates select="precondition">
            <xsl:with-param name="id" select="$id-self"/>
          </xsl:apply-templates>
        </div>
      </xsl:if>
    </div>

    <xsl:variable name="nr">
      <xsl:call-template name="make-number-impl">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="node-nr" select="$start-nr + $counted-nodes"/>
      </xsl:call-template>
    </xsl:variable>

    <xsl:call-template name="testgroup-detailed-impl">
      <xsl:with-param name="parent-nr" select="$nr"/>
      <xsl:with-param name="start-nr" select="0"/>
      <xsl:with-param name="id" select="$id-self"/>
    </xsl:call-template>

    <xsl:apply-templates select="." mode="end"/>
  </xsl:template>

  <xsl:template match="testgroup" mode="heading">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:param name="id"/>
    <table class="GroupHeadingTable">
      <tr>
        <xsl:apply-templates select="." mode="show-hide">
          <xsl:with-param name="id" select="$id"/>
        </xsl:apply-templates>
        <xsl:apply-templates select="." mode="link-up"/>
        <td>
          <big class="Heading3">
            <xsl:apply-templates select="." mode="heading-title">
              <xsl:with-param name="parent-nr" select="$parent-nr"/>
              <xsl:with-param name="start-nr" select="$start-nr"/>
            </xsl:apply-templates>
          </big>
        </td>
      </tr>
    </table>
  </xsl:template>
  <xsl:template match="testgroup" mode="heading-title">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <a name="{generate-id()}">
      <xsl:call-template name="testgroup-heading-title">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr"/>
      </xsl:call-template>
    </a>
  </xsl:template>
  <xsl:template name="testgroup-heading-title">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:choose>
      <xsl:when test="$ShowAutomaticTestModuleNumbering=true()">
        <xsl:call-template name="show-number-impl">
          <xsl:with-param name="parent-nr" select="$parent-nr"/>
          <xsl:with-param name="start-nr" select="$start-nr"/>
        </xsl:call-template>
        <xsl:text> Test Group</xsl:text>
        <xsl:if test="ident">
          <xsl:text> </xsl:text>
          <xsl:value-of select="ident"/>
        </xsl:if>
        <xsl:text>: </xsl:text>
        <xsl:value-of select="title"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:if test="ident">
          <xsl:value-of select="ident"/><xsl:text> </xsl:text>
        </xsl:if>
        <xsl:text> Test Group</xsl:text>
        <xsl:text>: </xsl:text>
        <xsl:value-of select="title"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <!-- Template: Overview of test cases -->
  <xsl:template match="testcase" mode="overview">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:call-template name="testcase-overview">
      <xsl:with-param name="parent-nr" select="$parent-nr"/>
      <xsl:with-param name="start-nr" select="$start-nr"/>
    </xsl:call-template>
  </xsl:template>
  <!-- Template: Controls the overview of testcases with failed preconditions -->
  <xsl:template match="testcase[./precondition/precondend[@fulfilled='false']]" mode="overview">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:if test="$ShowFailedPreconditions">
      <xsl:call-template name="testcase-overview">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr"/>
      </xsl:call-template>
    </xsl:if>
  </xsl:template>
  <xsl:template name="testcase-overview">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    <xsl:variable name="number">
      <xsl:call-template name="show-number-impl">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr + $counted-nodes"/>
      </xsl:call-template>
    </xsl:variable>
    <xsl:variable name="number-cycle">
      <xsl:if test="ancestor::testcycle">
        <xsl:call-template name="number-cycle"/>
        <xsl:text>.</xsl:text>
      </xsl:if>
    </xsl:variable>
    <tr>
      <xsl:if test="$ShowAutomaticTestModuleNumbering=true()">
        <td class="DefineCell">
          <xsl:value-of select="$number"/>
        </td>
      </xsl:if>
      <xsl:if test="$StructureIdents=true()">
        <td class="DefaultCell">
          <xsl:value-of select="ident" />
        </td>
      </xsl:if>
      <xsl:variable name="hide-tc">
        <xsl:call-template name="hidetestcase"/>
      </xsl:variable>
      <xsl:variable name="hide-tc-bool" select="boolean(number($hide-tc))"/>
      <xsl:choose>
        <xsl:when test="$hide-tc-bool">
          <td class="DefaultCell">
            <xsl:value-of select="title"/>
          </td>
        </xsl:when>
        <xsl:otherwise>
          <td class="DefaultCell">
            <xsl:call-template name="aHrefImpl">
              <xsl:with-param name="externalID" select="."/>
              <xsl:with-param name="externalFile" select="'.html'"/>
              <xsl:with-param name="anchorText" select="title"/>
            </xsl:call-template>
          </td>
        </xsl:otherwise>
      </xsl:choose>

      <xsl:choose>
        <xsl:when test="precondition/precondend[@fulfilled='false']">
          <td class="DefaultCell">
            <xsl:text>not executed due to precondition</xsl:text>
          </td>
        </xsl:when>
        <xsl:when test="verdict/@result='pass'">
          <td class="PositiveResultCell">
            <xsl:text>pass</xsl:text>
          </td>
        </xsl:when>
        <xsl:when test="verdict/@result='fail'">
          <td class="NegativeResultCell">
            <xsl:choose>
              <xsl:when test="not($HideFailTestCases) and (descendant::violation|descendant::teststep|descendant::checkstartupinfo|descendant::checkterminationinfo)[@result='fail']">
                <xsl:call-template name="aHrefImpl">
                  <xsl:with-param name="externalID" select="."/>
                  <xsl:with-param name="externalFile" select="'.html'"/>
                  <xsl:with-param name="internalID" select="(descendant::violation|descendant::teststep|descendant::checkstartupinfo|descendant::checkterminationinfo)[@result='fail'][1]"/>
                  <xsl:with-param name="anchorText" select="'fail'"/>
                  <xsl:with-param name="onclick">
                    <xsl:text>showTC('</xsl:text>
                    <xsl:value-of select="$number-cycle"/>
                    <xsl:value-of select="$number"/>
                    <xsl:text>')</xsl:text>
                  </xsl:with-param>
                </xsl:call-template>
              </xsl:when>
              <xsl:otherwise>
                <xsl:text>fail</xsl:text>
              </xsl:otherwise>
            </xsl:choose>
          </td>
        </xsl:when>
        <xsl:when test="verdict/@result='error'">
          <td class="ErrorResultCell">
            <xsl:choose>
              <xsl:when test="not($HideErrorTestCases) and (descendant::violation|descendant::teststep|descendant::checkstartupinfo|descendant::checkterminationinfo)[@result='error']">
                <xsl:call-template name="aHrefImpl">
                  <xsl:with-param name="externalID" select="."/>
                  <xsl:with-param name="externalFile" select="'.html'"/>
                  <xsl:with-param name="internalID" select="(descendant::violation|descendant::teststep|descendant::checkstartupinfo|descendant::checkterminationinfo)[@result='error'][1]"/>
                  <xsl:with-param name="anchorText" select="'error in test system'"/>
                  <xsl:with-param name="onclick">
                    <xsl:text>showTC('</xsl:text>
                    <xsl:value-of select="$number-cycle"/>
                    <xsl:value-of select="$number"/>
                    <xsl:text>')</xsl:text>
                  </xsl:with-param>
                </xsl:call-template>
              </xsl:when>
              <xsl:otherwise>
                <xsl:text>error in test system</xsl:text>
              </xsl:otherwise>
            </xsl:choose>
          </td>
        </xsl:when>
        <xsl:when test="verdict/@result='inconclusive'">
          <td class="InconclusiveResultCell">
            <xsl:choose>
              <xsl:when test="not($HideInconTestCases) and (descendant::violation|descendant::teststep|descendant::checkstartupinfo|descendant::checkterminationinfo)[@result='inconclusive']">
                <xsl:call-template name="aHrefImpl">
                  <xsl:with-param name="externalID" select="."/>
                  <xsl:with-param name="externalFile" select="'.html'"/>
                  <xsl:with-param name="internalID" select="(descendant::violation|descendant::teststep|descendant::checkstartupinfo|descendant::checkterminationinfo)[@result='inconclusive'][1]"/>
                  <xsl:with-param name="anchorText" select="'inconclusive'"/>
                  <xsl:with-param name="onclick">
                    <xsl:text>showTC('</xsl:text>
                    <xsl:value-of select="$number-cycle"/>
                    <xsl:value-of select="$number"/>
                    <xsl:text>')</xsl:text>
                  </xsl:with-param>
                </xsl:call-template>
              </xsl:when>
              <xsl:otherwise>
                <xsl:text>inconclusive</xsl:text>
              </xsl:otherwise>
            </xsl:choose>
          </td>
        </xsl:when>
        <xsl:when test="verdict/@result='none'">
          <td class="NoneResultCell">
            <xsl:text>none</xsl:text>
          </td>
        </xsl:when>
        <xsl:when test="verdict/@result='na'">
          <td class="DefaultCell">
            <xsl:text>not executed</xsl:text>
          </td>
        </xsl:when>
      </xsl:choose>
      <xsl:if test="$ShowWarningsInStatistics">
        <td>
          <xsl:choose>
            <xsl:when test="(descendant::teststep|descendant::checkstartupinfo|descendant::checkterminationinfo)[@result='warn']">
              <xsl:attribute name="class">WarningCell</xsl:attribute>
              <xsl:call-template name="aHrefImpl">
                <xsl:with-param name="externalID" select="."/>
                <xsl:with-param name="externalFile" select="'.html'"/>
                <xsl:with-param name="internalID" select="(descendant::teststep|descendant::checkstartupinfo|descendant::checkterminationinfo)[@result='warn'][1]"/>
                <xsl:with-param name="anchorText" select="'warning'"/>
              </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
              <xsl:attribute name="class">DefaultCell</xsl:attribute>
            </xsl:otherwise>
          </xsl:choose>
        </td>
      </xsl:if>
      <xsl:if test="$EnableSpecialVerdictInfo=true()">
        <td class="DefaultCell">
          <xsl:if test="miscinfo/title[text()='Verdict Information']">
            <xsl:value-of select="miscinfo/title[text()='Verdict Information']/../info[position()=1]/description"/>
          </xsl:if>
        </td>
      </xsl:if>
    </tr>
  </xsl:template>
  <!-- Template: Details of test cases -->
  <xsl:template name="testcase-detailed">
    <xsl:param name="parent-nr"/>
    <xsl:param name="start-nr" select="'0'"/>
    <xsl:param name="id"/>
    <xsl:variable name="counted-nodes">
      <xsl:call-template name="count-nodes-impl"/>
    </xsl:variable>
    <xsl:variable name="number">
      <xsl:call-template name="show-number-impl">
        <xsl:with-param name="parent-nr" select="$parent-nr"/>
        <xsl:with-param name="start-nr" select="$start-nr + $counted-nodes"/>
      </xsl:call-template>
    </xsl:variable>
    <xsl:variable name="id-self">
      <xsl:if test="string-length($id) > 0">
        <xsl:value-of select="$id"/>
        <xsl:text>.</xsl:text>
      </xsl:if>
      <xsl:value-of select="$start-nr + $counted-nodes + 1"/>
    </xsl:variable>

    <xsl:apply-templates select="." mode="link-up"/>

    <!-- Test Case Heading -->
    <xsl:variable name="BackgroundClass">
      <xsl:choose>
        <xsl:when test="verdict/@result='pass'">TestcaseHeadingPositiveResult</xsl:when>
        <xsl:when test="verdict/@result='fail'">TestcaseHeadingNegativeResult</xsl:when>
        <xsl:when test="verdict/@result='none'">TestcaseHeadingNoneResult</xsl:when>
        <xsl:when test="verdict/@result='inconclusive'">TestcaseHeadingInconclusiveResult</xsl:when>
        <xsl:when test="verdict/@result='error'">TestcaseHeadingErrorResult</xsl:when>
        <xsl:when test="verdict/@result='na'">TestcaseHeadingDefaultResult</xsl:when>
      </xsl:choose>
    </xsl:variable>
    <table>
      <tr>
        <xsl:apply-templates select="." mode="show-hide">
          <xsl:with-param name="id" select="$id-self"/>
        </xsl:apply-templates>
        <td class='{$BackgroundClass}'>
          <big class="Heading3">
            <!-- Test Case Result -->
            <xsl:if test="$ShowAutomaticTestModuleNumbering=true()">
              <xsl:value-of select="$number"/>
            </xsl:if>
            <xsl:text> </xsl:text>
            <a name="{generate-id()}">
              <xsl:choose>
                <xsl:when test="$StructureIdents=true()">
                  <xsl:choose>
                    <xsl:when test="ident">
                      <xsl:text>Test Case </xsl:text>
                      <xsl:value-of select="ident" />
                      <xsl:text>: </xsl:text>
                      <xsl:value-of select="title" />
                    </xsl:when>
                    <xsl:otherwise>
                      <xsl:value-of select="title" />
                    </xsl:otherwise>
                  </xsl:choose>
                </xsl:when>
                <xsl:otherwise>
                  <xsl:value-of select="title" />
                </xsl:otherwise>
              </xsl:choose>
            </a>
            <xsl:text>: </xsl:text>
            <xsl:choose>
              <xsl:when test="verdict/@result='pass'">Passed</xsl:when>
              <xsl:when test="verdict/@result='fail'">Failed</xsl:when>
              <xsl:when test="verdict/@result='none'">None</xsl:when>
              <xsl:when test="verdict/@result='inconclusive'">Inconclusive</xsl:when>
              <xsl:when test="verdict/@result='error'">Error in test system</xsl:when>
              <xsl:when test="verdict/@result='na'">Not Executed</xsl:when>
            </xsl:choose>
          </big>
        </td>
      </tr>
    </table>

    <div class="Indentation">
      <xsl:attribute name="id">
        <xsl:value-of select="$DivPrefix"/>
        <xsl:value-of select="$id-self"/>
      </xsl:attribute>
      <!-- Testcase description-->
      <xsl:apply-templates select="description" mode="paragraph"/>

      <div class="Indentation">
        <!-- Test Case Begin/End -->
        <xsl:call-template name="beginend">
          <xsl:with-param name="what">Test case</xsl:with-param>
          <xsl:with-param name="nodeset" select=".|verdict"/>
        </xsl:call-template>

        <!-- Measured Result -->
        <xsl:apply-templates select="measuredresults"/>

        <!-- External references -->
        <xsl:apply-templates select="externalref"/>

        <!-- Test case miscellaneous information -->
        <xsl:apply-templates select="miscinfo"/>

        <!-- Test case extended information -->
        <xsl:apply-templates select="extendedinfo"/>

        <!-- Check statistics of test case -->
        <xsl:if test="checkstatistic">
				
				<xsl:apply-templates select="checkstatistic" mode="report"/>
        </xsl:if>
      </div>

      <div class="Indentation">
        <!-- expand/collapse tabularinfo from a teststep -->
        <xsl:if test="descendant::tabularinfo">
          <xsl:apply-templates select="." mode="tabularinfo">
            <xsl:with-param name="id" select="$id-self"/>
          </xsl:apply-templates>
        </xsl:if>
      </div>

      <!-- Precondition section of test case -->
      <xsl:if test="precondition">
        <table class="TestGroupHeadingBackground">
          <tr>
            <td>
              <big class="Heading3">Precondition of Test Case</big>
            </td>
          </tr>
        </table>
        <div class="Indentation">
          <xsl:apply-templates select="precondition">
            <xsl:with-param name="id" select="$id-self"/>
          </xsl:apply-templates>
        </div>
      </xsl:if>

      <xsl:if test="vardef">
        <xsl:call-template name="vardef-table">
          <xsl:with-param name="title" select="'Variable definition'"/>
        </xsl:call-template>
      </xsl:if>

      <!-- Preparation section of test case -->
      <xsl:apply-templates select="preparation">
        <xsl:with-param name="id" select="$id-self"/>
      </xsl:apply-templates>

      <!-- Add information about Teststeps, Testpatterns, Details, Violations -->
      <xsl:if test="teststep|testpattern|details|comment|violation|command|checkbegin|checkend|checkstartupinfo|checkterminationinfo">
        <table class="TestGroupHeadingBackground">
          <tr>
            <td>
              <big class="Heading3">Main Part of Test Case</big>
            </td>
          </tr>
        </table>
        <xsl:variable name="ResultTableClass">
          <xsl:choose>
            <xsl:when test="parent::command">ResultTableInner</xsl:when>
            <xsl:otherwise>ResultTable</xsl:otherwise>
          </xsl:choose>
        </xsl:variable>
        <div class="Indentation">
          <table class="{$ResultTableClass}">
            <xsl:call-template name="teststep-header"/>
            <xsl:apply-templates select="teststep|testpattern|details|comment|violation|command|checkbegin|checkend|checkstartupinfo|checkterminationinfo" mode="testcase">
              <xsl:with-param name="id" select="$id-self"/>
            </xsl:apply-templates>
          </table>
        </div>
      </xsl:if>

      <!-- Completion section of test case -->
      <xsl:apply-templates select="completion">
        <xsl:with-param name="id" select="$id-self"/>
      </xsl:apply-templates>
    </div>
  </xsl:template>
  <xsl:template match="testcase" mode="tabularinfo">
    <xsl:param name="id"/>
    <xsl:call-template name="show-hide-tables">
      <xsl:with-param name="id" select="concat($id, '_')"/>
    </xsl:call-template>
  </xsl:template>

  <!-- Template: Overview of skipped test cases -->
  <xsl:template match="skipped" mode="overview">
    <tr>
      <xsl:if test="$ShowAutomaticTestModuleNumbering=true()">
        <td class="DefineCell"/>
      </xsl:if>
      <xsl:if test="$StructureIdents=true()">
        <td class="DefaultCell"><xsl:value-of select="ident"/></td>
      </xsl:if>
      <td class="DefaultCell"><xsl:value-of select="title"/></td>
      <td class="DefaultCell"><xsl:text>not executed</xsl:text></td>
      <xsl:if test="$ShowWarningsInStatistics">
        <td class="DefaultCell"/>
      </xsl:if>
      <xsl:if test="$EnableSpecialVerdictInfo=true()">
        <td class="DefaultCell"/>
      </xsl:if>
    </tr>
  </xsl:template>

  <!-- Template: Details of teststeps -->
  <xsl:template match="teststep">
    <xsl:param name="id"/>
    <xsl:call-template name="teststep">
      <xsl:with-param name="id" select="$id"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="teststep" mode="testcase">
    <xsl:param name="id"/>
    <xsl:call-template name="teststep">
      <xsl:with-param name="id" select="$id"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template name="teststep">
    <xsl:param name="id"/>
    <xsl:variable name="ActualLevel">
      <xsl:choose>
        <xsl:when test="@level"><xsl:value-of select="@level" /></xsl:when>
        <xsl:otherwise>0</xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:variable name="ShowStep">
      <xsl:choose>
        <xsl:when test="(@result='fail' or @result='inconclusive' or @result='error') and ($IncludeFailedStepsOnAnyLevel=true())">
          <xsl:value-of select="true()"/>
        </xsl:when>
        <xsl:when test="$ActualLevel &lt;= $TestStepMaxLevel">
          <xsl:value-of select="true()"/>
        </xsl:when>
        <xsl:otherwise>
          <xsl:value-of select="false()"/>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:if test="$ShowStep=string(true())">
      <!-- One level of indentation for each surrounding testpattern: -->
      <xsl:variable name="IndentLevel" select="count(ancestor::testpattern|ancestor::command)"/>
      <xsl:variable name="Indent" select="$IndentLevel*$IndentDepth"/>
      <xsl:variable name="NestingLevel">
        <xsl:choose>
          <xsl:when test="@indent"><xsl:value-of select="@indent"/></xsl:when>
          <xsl:otherwise><xsl:value-of select="0"/></xsl:otherwise>
        </xsl:choose>
      </xsl:variable>
      <xsl:variable name="Nesting" select="$NestingLevel*$IndentDepth"/>
      <tr>
        <!-- add anchor for 'fail' link from overview table (use id instead of <a name> to be able to link to top of row): -->
        <xsl:if test="@result='fail' or @result='warn' or @result='error' or @result='inconclusive'">
          <xsl:attribute name="id">
            <xsl:value-of select="generate-id(.)"/>
          </xsl:attribute>
        </xsl:if>
        <td>
          <xsl:if test="$Indent">
            <xsl:attribute name="style">text-indent: <xsl:value-of select="$Indent"/>px;</xsl:attribute>
          </xsl:if>
          <xsl:attribute name="class">DefineCell</xsl:attribute>
          <!-- must be *after* a possible style attribute! -->
          <xsl:call-template name="showTimeStampImpl">
            <xsl:with-param name="timeStampValue" select="@timestamp"/>
          </xsl:call-template>
        </td>
		<xsl:choose>
		  <xsl:when test="@result='na'">		    
			<xsl:choose>		  
				<xsl:when test="string-length(@ident) > 1">
					<td class="DefaultCellTestStepCellBlueUnderline">				    
						<xsl:value-of select="@ident"/>
						<xsl:if test="@ident = 'STEP'">
							<xsl:value-of select="'&#160;'"/>
							<xsl:value-of select="count(preceding-sibling::*[@ident = 'STEP']) + 1"/>	
						</xsl:if>
						<xsl:if test="@detectedAt">
							<xsl:if test="string-length(@ident) > 0"><br/></xsl:if>
							<xsl:value-of select="@detectedText"/>
							<xsl:call-template name="showTimeStampImpl">
								<xsl:with-param name="timeStampValue" select="@detectedAt"/>
							</xsl:call-template>
					</xsl:if>
					</td>
				</xsl:when>
				<xsl:otherwise>
					<td class="DefaultCell">
						<xsl:value-of select="@ident" />
						<xsl:if test="@detectedAt">
							<xsl:if test="string-length(@ident) > 0"><br/></xsl:if>
							<xsl:value-of select="@detectedText"/>
							<xsl:call-template name="showTimeStampImpl">
								<xsl:with-param name="timeStampValue" select="@detectedAt"/>
						</xsl:call-template>
					</xsl:if>
					</td>
				</xsl:otherwise>
			</xsl:choose>
		  </xsl:when>
		  <xsl:when test="@result='pass'"> 
			<td class="NumberCellPositiveResult">
				<xsl:value-of select="@ident" />
				<xsl:if test="@detectedAt">
					<xsl:if test="string-length(@ident) > 0"><br/></xsl:if>
					<xsl:value-of select="@detectedText"/>
					<xsl:call-template name="showTimeStampImpl">
						<xsl:with-param name="timeStampValue" select="@detectedAt"/>
				</xsl:call-template>
			</xsl:if>
			</td>
		  </xsl:when>
		  <xsl:when test="@result='fail'"> 
			<td class="NumberCellNegativeResult">
				<xsl:value-of select="@ident" />
				<xsl:if test="@detectedAt">
					<xsl:if test="string-length(@ident) > 0"><br/></xsl:if>
					<xsl:value-of select="@detectedText"/>
					<xsl:call-template name="showTimeStampImpl">
						<xsl:with-param name="timeStampValue" select="@detectedAt"/>
				</xsl:call-template>
			</xsl:if>
			</td>
		  </xsl:when>
		  <xsl:otherwise>
			<td class="NumberCell">
				<xsl:value-of select="@ident" />
				<xsl:if test="@detectedAt">
					<xsl:if test="string-length(@ident) > 0"><br/></xsl:if>
					<xsl:value-of select="@detectedText"/>
					<xsl:call-template name="showTimeStampImpl">
						<xsl:with-param name="timeStampValue" select="@detectedAt"/>
				</xsl:call-template>
			</xsl:if>
			</td>
		  </xsl:otherwise>
		</xsl:choose>
        <td>
          <xsl:if test="$Nesting">
            <xsl:attribute name="style">text-indent: <xsl:value-of select="$Nesting"/>px;</xsl:attribute>
          </xsl:if>
		  <xsl:choose>
			  <xsl:when test="@result='na'"> 
			  <xsl:choose>		  
					<xsl:when test="string-length(@ident) > 1">
						<xsl:attribute name="class">DefaultCellTestStep</xsl:attribute>
					</xsl:when>
					<xsl:otherwise>
						<xsl:attribute name="class">DefaultCell</xsl:attribute>
					</xsl:otherwise>
			  </xsl:choose>
				
			  </xsl:when>
			  <xsl:otherwise>
				  <xsl:attribute name="class">DefaultCell</xsl:attribute>
			  </xsl:otherwise>
		  </xsl:choose>
          <!-- must be *after* a possible style attribute! -->
          <xsl:choose>
            <xsl:when test="tabularinfo">
              <!-- teststep with tabularinfo child element => structured data follows -->
              <xsl:apply-templates select="tabularinfo">
                <xsl:with-param name="id" select="$id"/>
              </xsl:apply-templates>
            </xsl:when>
            <xsl:otherwise>
              <!-- normal teststep with just text content -->
              <xsl:call-template name="replacelinebreak">
                <xsl:with-param name="srcnode">
                  <xsl:value-of select="." />
                </xsl:with-param>
              </xsl:call-template>
            </xsl:otherwise>
          </xsl:choose>
        </td>
        <xsl:choose>
          <xsl:when test="@result='na'">
		  <xsl:choose>		  
				<xsl:when test="string-length(@ident) > 1">
					<td class="DefaultCellTestStep"><xsl:text>-</xsl:text></td>
				</xsl:when>
				<xsl:otherwise>
					<td class="DefaultCell"><xsl:text>-</xsl:text></td>
				</xsl:otherwise>
			</xsl:choose>
            
          </xsl:when>
          <xsl:when test="@result='none'">
            <td class="NoneResultCell"><xsl:text>none</xsl:text></td>
          </xsl:when>
          <xsl:when test="@result='pass'">
            <td class="PositiveResultCell"><xsl:text>pass</xsl:text></td>
          </xsl:when>
          <xsl:when test="@result='fail'">
            <td class="NegativeResultCell"><xsl:text>fail</xsl:text></td>
          </xsl:when>
          <xsl:when test="@result='warn'">
            <td class="WarningCell"><xsl:text>warning</xsl:text></td>
          </xsl:when>
          <xsl:when test="@result='inconclusive'">
            <td class="InconclusiveResultCell"><xsl:text>inconclusive</xsl:text></td>
          </xsl:when>
          <xsl:when test="@result='error'">
            <td class="ErrorResultCell"><xsl:text>error in test system</xsl:text></td>
          </xsl:when>
        </xsl:choose>
      </tr>
    </xsl:if>
  </xsl:template>
  <xsl:template name="countCellChars">
    <xsl:param name="cellNode"/>
    <xsl:param name="tmp"/>
    <xsl:variable name="mychars">
      <xsl:choose>
        <xsl:when test="$cellNode/@rowspan"><xsl:value-of select="string-length($cellNode) div $cellNode/@rowspan"/></xsl:when>
        <xsl:otherwise><xsl:value-of select="string-length($cellNode)"/></xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:variable name="result">
      <xsl:choose>
        <xsl:when test="$cellNode/following-sibling::cell">
          <xsl:call-template name="countCellChars">
            <xsl:with-param name="cellNode" select="$cellNode/following-sibling::cell[1]"/>
            <xsl:with-param name="tmp" select="$mychars + $tmp"/>
          </xsl:call-template>
        </xsl:when>
        <xsl:otherwise>
          <xsl:value-of select="$mychars + $tmp"/>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:value-of select="$result"/>
  </xsl:template>

  <xsl:template match="tabularinfo">
    <xsl:param name="id"/>
    <!-- expand/collapse link -->
    <table class="NoMarginBottom">
      <tbody>
        <tr>
          <td>
            <a class="Undecorated">
              <xsl:variable name="id-self">
                <xsl:value-of select="$id"/>
                <xsl:text>_</xsl:text>
                <xsl:value-of select="generate-id(.)"/>
              </xsl:variable>
              <xsl:attribute name="id">
                <xsl:value-of select="$TablePrefix"/>
                <xsl:value-of select="$id-self"/>
              </xsl:attribute>
              <xsl:attribute name="href">
                <xsl:text>javascript:switchTable('</xsl:text>
                <xsl:value-of select="$id-self"/>
                <xsl:text>')</xsl:text>
              </xsl:attribute>
              <xsl:value-of select="$ExpandedText"/>
            </a>
          </td>
          <td>
            <xsl:call-template name="replacelinebreak">
              <xsl:with-param name="srcnode">
                <xsl:value-of select="description"/>
              </xsl:with-param>
            </xsl:call-template>
          </td>
        </tr>
      </tbody>
    </table>

    <table class="InfoTable">
      <xsl:attribute name="class">
        <xsl:if test="@expand='true'">InfoTableExpand</xsl:if>
        <xsl:if test="not(@expand='true')">InfoTable</xsl:if>
      </xsl:attribute>

      <!-- write the id attribute for expand-collapse  -->
      <xsl:attribute name="id">
        <xsl:value-of select="$TablePrefix"/>
        <xsl:value-of select="$id"/>
        <xsl:text>_</xsl:text>
        <xsl:value-of select="generate-id(.)"/>
      </xsl:attribute>

      <xsl:for-each select="row|heading">
        <xsl:variable name="CellClass">
          <xsl:choose>
            <xsl:when test="local-name()='heading'">DefineCell</xsl:when>
            <xsl:otherwise>DefaultCell</xsl:otherwise>
          </xsl:choose>
        </xsl:variable>
        <xsl:variable name="RowIndent">
          <xsl:choose>
            <xsl:when test="@level"><xsl:value-of select="@level*$IndentDepth"/></xsl:when>
            <xsl:otherwise>0</xsl:otherwise>
          </xsl:choose>
        </xsl:variable>
        <tr>
          <xsl:variable name="HasAnyRowSpan" select="boolean(cell/@rowspan)"/>
          <xsl:variable name="TotalLineChars">
            <xsl:if test="$HasAnyRowSpan=true()">
              <xsl:call-template name="countCellChars">
                <xsl:with-param name="cellNode" select="cell[1]"/>
                <xsl:with-param name="tmp" select="0"/>
              </xsl:call-template>
            </xsl:if>
          </xsl:variable>
          <xsl:for-each select="cell">
            <xsl:variable name="CurrentPos" select="position()+sum(preceding-sibling::*/@colspan)-count(preceding-sibling::*[@colspan])"/>
            <td>
              <xsl:if test="$HasAnyRowSpan=true()">
                <!--
                  If cells in this row have a rowspan attribute, it's because one of them contains a large amount of text
                  and they all span the same number of lines. We try to distribute column width percentages reasonably by assuming that
                  the non-spanned cells should not wrap and the spanned cells should wrap to approx. the same number of lines
                  as there are non-spanned cells. Calculate percentages based on number of characters per cell divided by spanned rows.
                 -->
                <xsl:if test="@rowspan">
                  <xsl:attribute name="rowspan"><xsl:value-of select="@rowspan"/></xsl:attribute>
                </xsl:if>
                <xsl:variable name="MyRowSpan">
                  <xsl:choose>
                    <xsl:when test="@rowspan"><xsl:value-of select="@rowspan"/></xsl:when>
                    <xsl:otherwise>1</xsl:otherwise>
                  </xsl:choose>
                </xsl:variable>
                <xsl:variable name="MyWidth" select="(100 * string-length(.) div number($MyRowSpan)) div number($TotalLineChars)"/>
                <xsl:attribute name="width">
                  <xsl:value-of select="round($MyWidth)"/><xsl:text>%</xsl:text>
                </xsl:attribute>
              </xsl:if>
              <xsl:variable name="CellVerdictClass">
                <xsl:if test="parent::row/preceding-sibling::heading/cell[text()='Result' and (position()+sum(preceding-sibling::*/@colspan)-count(preceding-sibling::*[@colspan]))=$CurrentPos]">
                  <xsl:choose>
                    <xsl:when test="text()='pass'">PositiveResultCell</xsl:when>
                    <xsl:when test="text()='fail'">NegativeResultCell</xsl:when>
                    <xsl:when test="text()='inconclusive'">InconclusiveResultCell</xsl:when>
                    <xsl:when test="text()='error'">ErrorResultCell</xsl:when>
                    <xsl:when test="text()='warning'">WarningCell</xsl:when>
                    <xsl:when test="text()='none'">NoneResultCell</xsl:when>
                  </xsl:choose>
                </xsl:if>
              </xsl:variable>
              <xsl:attribute name="class">
                <xsl:choose>
                  <xsl:when test="string-length($CellVerdictClass)>0"><xsl:value-of select="$CellVerdictClass"/></xsl:when>
                  <xsl:otherwise><xsl:value-of select="$CellClass"/></xsl:otherwise>
                </xsl:choose>
              </xsl:attribute>
              <xsl:if test="position()=1">
                <xsl:attribute name="style">text-indent: <xsl:value-of select="$RowIndent"/>px;</xsl:attribute>
              </xsl:if>
              <xsl:if test="@colspan">
                <xsl:attribute name="colspan"><xsl:value-of select="@colspan"/></xsl:attribute>
              </xsl:if>
              <xsl:if test="text()='Result'">
                <xsl:attribute name="width">1px</xsl:attribute>
              </xsl:if>
              <xsl:value-of select="."/>
            </td>
          </xsl:for-each>
        </tr>
      </xsl:for-each>
    </table>
  </xsl:template>

  <xsl:template match="preparation|completion" mode="tabularinfo">
    <xsl:param name="id"/>
    <xsl:call-template name="show-hide-tables">
      <xsl:with-param name="id" select="concat($id, '_')"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="preparation[ancestor::testcase]|completion[ancestor::testcase]" mode="tabularinfo"/>

  <!-- Template: Comment -->
  <xsl:template match="comment">
    <xsl:call-template name="comment-inlined"/>
  </xsl:template>

  <!-- Template: Comment in Test Case -->
  <xsl:template match="comment" mode="testcase">
    <xsl:call-template name="comment-inlined"/>
  </xsl:template>

  <!-- Template: Comment inlined in result table -->
  <xsl:template name="comment-inlined">
    <tr>
      <!-- One level of indentation for each surrounding testpattern -->
      <xsl:variable name="IndentLevel" select="count(ancestor::testpattern|ancestor::command)"/>
      <xsl:variable name="Indent" select="$IndentLevel*$IndentDepth"/>
      <td>
        <xsl:if test="$Indent">
          <xsl:attribute name="style">text-indent: <xsl:value-of select="$Indent"/>px;</xsl:attribute>
        </xsl:if>
        <xsl:attribute name="class">DefineCell</xsl:attribute>
        <!-- must be *after* a possible style attribute! -->
        <xsl:call-template name="showTimeStampImpl">
          <xsl:with-param name="timeStampValue" select="@timestamp"/>
        </xsl:call-template>
      </td>
      <td class="DefaultCellBold"/>
      <td class="DefaultCellBold">
          <xsl:choose>
            <xsl:when test="text">
              <xsl:call-template name="replacelinebreak">
                <xsl:with-param name="srcnode" select="text"/>
              </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
              <xsl:call-template name="replacelinebreak">
                <xsl:with-param name="srcnode" select="."/>
              </xsl:call-template>
            </xsl:otherwise>
          </xsl:choose>
        <xsl:if test="image">
          <br/>
          <xsl:apply-templates select="image"/>
        </xsl:if>
      </td>
      <td class="DefaultCellBold">
        <xsl:text>-</xsl:text>
      </td>
    </tr>
  </xsl:template>

  <!-- Template: Details -->
  <xsl:template match="details">
    <xsl:call-template name="details"/>
  </xsl:template>
  <xsl:template match="details" mode="testcase">
    <xsl:call-template name="details"/>
  </xsl:template>
  <xsl:template name="details">
    <tr>
      <!-- One level of indentation for each surrounding testpattern -->
      <xsl:variable name="IndentLevel" select="count(ancestor::testpattern|ancestor::command)"/>
      <xsl:variable name="Indent" select="$IndentLevel*$IndentDepth"/>
      <td>
        <xsl:if test="$Indent">
          <xsl:attribute name="style">text-indent: <xsl:value-of select="$Indent"/>px;</xsl:attribute>
        </xsl:if>
        <xsl:attribute name="class">DefineCell</xsl:attribute>
        <!-- must be *after* a possible style attribute! -->
        <xsl:call-template name="showTimeStampImpl">
          <xsl:with-param name="timeStampValue" select="@timestamp"/>
        </xsl:call-template>
      </td>
      <td class="DefaultCell"/>
      <td class="DefaultCell">
        <xsl:if test="title">
          <xsl:value-of select="title" /><br />
        </xsl:if>
        <xsl:apply-templates select="image|value|info|canmsg|mostmsg|mostsysmsg|linframe|gmlanmsg" />
      </td>
      <td class="DefaultCell"><xsl:text>-</xsl:text></td>
    </tr>
  </xsl:template>

  <!-- Template: Violation on testmodule level -->
  <xsl:template match="violation" mode="testmodule">
    <xsl:apply-templates select="." mode="outside-testcase"/>
  </xsl:template>
  <!-- Template: Violation -->
  <xsl:template match="violation">
    <xsl:call-template name="violation"/>
  </xsl:template>
  <xsl:template match="violation" mode="testcase">
    <xsl:call-template name="violation"/>
  </xsl:template>
  <xsl:template name="violation">
    <!-- One level of indentation for each surrounding testpattern -->
    <xsl:variable name="IndentLevel" select="count(ancestor::testpattern|ancestor::command)"/>
    <xsl:variable name="Indent" select="$IndentLevel*$IndentDepth"/>
    <tr>
      <!-- add anchor for 'fail' link from overview table (use id instead of <a name> to be able to link to top of row): -->
      <xsl:if test="(@result='inconclusive' or @result='fail' or @result='error')">
        <xsl:attribute name="id">
          <xsl:value-of select="generate-id(.)"/>
        </xsl:attribute>
      </xsl:if>
      <td>
        <xsl:if test="$Indent">
          <xsl:attribute name="style">text-indent: <xsl:value-of select="$Indent"/>px;</xsl:attribute>
        </xsl:if>
        <xsl:attribute name="class">DefineCell</xsl:attribute>
        <!-- must be *after* a possible style attribute! -->
        <xsl:call-template name="showTimeStampImpl">
          <xsl:with-param name="timeStampValue" select="@timestamp"/>
        </xsl:call-template>
      </td>

      <td>
        <xsl:attribute name="class">
          <xsl:apply-templates select="." mode="violation-class"/>
        </xsl:attribute>
        <xsl:apply-templates select="." mode="violation-ident"/>
        <xsl:apply-templates select="." mode="violation-ident-result"/>
        <xsl:if test="@detectedAt">
          <xsl:text> at </xsl:text>
          <xsl:call-template name="showTimeStampImpl">
            <xsl:with-param name="timeStampValue" select="@detectedAt"/>
          </xsl:call-template>
        </xsl:if>
      </td>
      <td>
        <xsl:attribute name="class">
          <xsl:apply-templates select="." mode="violation-class"/>
        </xsl:attribute>
        <xsl:apply-templates select="." mode="link2statistic"/>
        <xsl:call-template name="replacelinebreak">
          <xsl:with-param name="srcnode" select="."/>
        </xsl:call-template>
      </td>
      <td>
        <xsl:attribute name="class">
          <xsl:apply-templates select="." mode="violation-class"/>
        </xsl:attribute>
        <xsl:apply-templates select="." mode="violation-result"/>
      </td>
    </tr>
  </xsl:template>
  <!-- Template: Violation on testunit level -->
  <xsl:template match="violation" mode="outside-testcase">
    <tr>
      <td class="DefineCell">
        <xsl:call-template name="showTimeStampImpl">
          <xsl:with-param name="timeStampValue" select="@timestamp"/>
        </xsl:call-template>
      </td>
      <td>
        <xsl:attribute name="class">
          <xsl:apply-templates select="." mode="violation-class"/>
        </xsl:attribute>
        <xsl:apply-templates select="." mode="violation-ident"/>
        <xsl:apply-templates select="." mode="violation-ident-result"/>
      </td>
      <td class="DefaultCell">
        <xsl:call-template name="replacelinebreak">
          <xsl:with-param name="srcnode" select="."/>
        </xsl:call-template>
      </td>
    </tr>
  </xsl:template>

   <!-- violation: ident first word -->
  <xsl:template match="violation[@type='condition']" mode="violation-ident">
    <xsl:text>Condition </xsl:text>
  </xsl:template>
  <xsl:template match="violation[@type='constraint']" mode="violation-ident">
    <xsl:text>Constraint </xsl:text>
  </xsl:template>
  <xsl:template match="violation[@type='program']" mode="violation-ident">
    <xsl:text>Program </xsl:text>
  </xsl:template>
  <xsl:template match="violation[@type='warning']" mode="violation-ident">
    <xsl:text>Program </xsl:text>
  </xsl:template>
  <xsl:template match="violation[@type='observation']" mode="violation-ident">
    <xsl:text>Observation </xsl:text>
  </xsl:template>

  <!-- violation: ident second word -->
  <xsl:template match="violation[@result='warn']" mode="violation-ident-result">
    <xsl:text>warning</xsl:text>
  </xsl:template>
  <xsl:template match="violation[@type='observation']" mode="violation-ident-result">
    <xsl:text>info</xsl:text>
  </xsl:template>
  <xsl:template match="violation" mode="violation-ident-result">
    <xsl:text>violation</xsl:text>
  </xsl:template>

  <!-- violation: background color -->
  <xsl:template match="violation[@result='error']" mode="violation-class">
    <xsl:text>ErrorResultCell</xsl:text>
  </xsl:template>
  <xsl:template match="violation[@result='inconclusive']" mode="violation-class">
    <xsl:text>InconclusiveResultCell</xsl:text>
  </xsl:template>
  <xsl:template match="violation[@result='warn']" mode="violation-class">
    <xsl:text>WarningCell</xsl:text>
  </xsl:template>
  <xsl:template match="violation[@type='observation']" mode="violation-class">
    <xsl:text>DefaultCell</xsl:text>
  </xsl:template>
  <xsl:template match="violation" mode="violation-class">
    <xsl:text>NegativeResultCell</xsl:text>
  </xsl:template>

  <!-- violation: text in verdict column -->
  <xsl:template match="violation[@result='error']" mode="violation-result">
    <xsl:text>error in test system</xsl:text>
  </xsl:template>
  <xsl:template match="violation[@result='inconclusive']" mode="violation-result">
    <xsl:text>inconclusive</xsl:text>
  </xsl:template>
  <xsl:template match="violation[@result='warn']" mode="violation-result">
    <xsl:text>-</xsl:text>
  </xsl:template>
  <xsl:template match="violation[@type='observation']" mode="violation-result">
    <xsl:text>-</xsl:text>
  </xsl:template>
  <xsl:template match="violation" mode="violation-result">
    <xsl:text>fail</xsl:text>
  </xsl:template>

  <!-- Template: meaured results -->
  <xsl:template match="measuredresults">
    <div class="Heading4">Measured Values</div>
    <div class="Indentation">
      <table class="OverviewTable">
        <tr>
          <td class="TableHeadingCell">Name</td>
          <td class="TableHeadingCell">Value</td>
          <td class="TableHeadingCell">Unit</td>
        </tr>
        <xsl:apply-templates select="measuredresult"/>
      </table>
    </div>
  </xsl:template>
  <xsl:template match="measuredresult">
    <tr>
      <td class="DefaultCell">
        <xsl:value-of select="@name"/>
      </td>
      <td class="DefaultCell">
        <xsl:value-of select="@value"/>
      </td>
      <td class="DefaultCell">
        <xsl:value-of select="@unit"/>
      </td>
    </tr>
  </xsl:template>

  <!-- Template: external references -->
  <xsl:template match="externalref">
    <xsl:variable name="ExtRefTitle">
      <xsl:choose>
        <xsl:when test="@title"><xsl:value-of select="@title"/></xsl:when>
        <xsl:otherwise><xsl:value-of select="."/></xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <p>
      <xsl:choose>
        <xsl:when test="@type='url'">
          <b><xsl:text>External Resource</xsl:text></b>
          <xsl:if test="@owner"><xsl:text> (managed by: </xsl:text><xsl:value-of select="@owner"/><xsl:text>)</xsl:text></xsl:if>
          <xsl:text>: </xsl:text>
          <a><xsl:attribute name="href"><xsl:value-of select="."/></xsl:attribute><xsl:value-of select="$ExtRefTitle"/></a>
        </xsl:when>
        <xsl:when test="@type='doors'">
          <b><xsl:text>DOORS Link</xsl:text></b>
          <xsl:if test="@owner"><xsl:text> (managed by: </xsl:text><xsl:value-of select="@owner"/><xsl:text>)</xsl:text></xsl:if>
          <xsl:text>: </xsl:text>
          <a><xsl:attribute name="href"><xsl:value-of select="."/></xsl:attribute><xsl:value-of select="$ExtRefTitle"/></a>
        </xsl:when>
        <xsl:when test="@type='easee'">
          <b><xsl:text>eASEE Link</xsl:text></b>
          <xsl:if test="@owner"><xsl:text> (managed by: </xsl:text><xsl:value-of select="@owner"/><xsl:text>)</xsl:text></xsl:if>
          <xsl:text>: </xsl:text>
          <a><xsl:attribute name="href"><xsl:value-of select="."/></xsl:attribute><xsl:value-of select="$ExtRefTitle"/></a>
        </xsl:when>
        <xsl:when test="@owner='vTESTstudio Traceability'">
          <b>
            <xsl:value-of select="@type"/>
            <xsl:text> Link</xsl:text>
          </b>
          <xsl:text> (managed by: </xsl:text><xsl:value-of select="@owner"/><xsl:text>)</xsl:text>
          <xsl:text>: </xsl:text>
          <a><xsl:attribute name="href"><xsl:value-of select="."/></xsl:attribute><xsl:value-of select="$ExtRefTitle"/></a>
        </xsl:when>
        <xsl:otherwise>
          <b><xsl:value-of select="@type"/></b>
          <xsl:if test="@owner"><xsl:text> (managed by: </xsl:text><xsl:value-of select="@owner"/><xsl:text>)</xsl:text></xsl:if>
          <xsl:text>: </xsl:text>
          <xsl:value-of select="$ExtRefTitle"/>
          <xsl:if test="string-length(normalize-space()) > 0">
            <xsl:text> [</xsl:text><xsl:value-of select="."/><xsl:text>]</xsl:text>
          </xsl:if>
        </xsl:otherwise>
      </xsl:choose>
    </p>
  </xsl:template>
  <!-- Template: extended info -->
  <xsl:template match="extendedinfo">
    <p>
      <xsl:choose>
        <xsl:when test="./@type='html'">
          <xsl:value-of select="." disable-output-escaping="yes"/>
        </xsl:when>
        <xsl:when test="./@type='text'">
          <xsl:call-template name="replacelinebreak">
            <xsl:with-param name="srcnode"><xsl:value-of select="." /></xsl:with-param>
          </xsl:call-template>
        </xsl:when>
        <xsl:otherwise>
          <xsl:text>Info with content type 'other' suppressed. See XML report for content.</xsl:text>
        </xsl:otherwise>
      </xsl:choose>
    </p>
  </xsl:template>
  <!-- Template: misc info -->
  <xsl:template match="miscinfo">
    <div class="Heading4"><xsl:value-of select="title" /></div>
    <div class="Indentation">
      <table>
        <xsl:for-each select="info">
          <tr>
            <xsl:choose>
              <xsl:when test="name[text()!='']">
                <td class="DefaultCell"><xsl:value-of select="name" /><xsl:text>: </xsl:text></td>
                <td class="DefaultCellBold">
                  <xsl:call-template name="replacelinebreak">
                    <xsl:with-param name="srcnode">
                      <xsl:value-of select="description" />
                    </xsl:with-param>
                  </xsl:call-template>
                </td>
              </xsl:when>
              <xsl:otherwise>
                <td class="CellNoColor" colspan="2">
                  <xsl:call-template name="replacelinebreak">
                    <xsl:with-param name="srcnode">
                      <xsl:value-of select="description" />
                    </xsl:with-param>
                  </xsl:call-template>
                </td>
              </xsl:otherwise>
            </xsl:choose>
          </tr>
        </xsl:for-each>
      </table>
    </div>
  </xsl:template>
  <xsl:template name="vardef-table">
    <xsl:param name="title">Variables:</xsl:param>
    <div class="Heading5">
      <xsl:value-of select="$title"></xsl:value-of>
    </div>
    <div class="Indentation">
      <table class="OverviewTable">
        <tr>
          <th class="TableHeadingCell">Name</th>
          <th class="TableHeadingCell">Type</th>
          <th class="TableHeadingCell">Value</th>
          <xsl:if test="vardef/testerquestion">
            <th class="TableHeadingCell">Question/Text</th>
          </xsl:if>
          <xsl:if test="vardef/testerinput/description">
            <th class="TableHeadingCell">Comment</th>
          </xsl:if>
        </tr>
        <xsl:apply-templates select="vardef" />
      </table>
    </div>
  </xsl:template>
  <!-- Template: Variable Definition -->
  <xsl:template match="vardef">
    <tr>
      <td class="DefineCell"><xsl:value-of select="@name" /></td>
      <td class="DefaultCell"><xsl:value-of select="@type" /></td>
      <xsl:choose>
        <xsl:when test="testerinput/inputvalue">
          <td class="DefaultCell"><xsl:value-of select="testerinput/inputvalue" /></td>
        </xsl:when>
        <xsl:otherwise>
          <td class="DefaultCell"><xsl:value-of select="." /></td>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:if test="../vardef/testerquestion">
        <td class="DefaultCell"><xsl:value-of select="testerquestion" /></td>
      </xsl:if>
      <xsl:if test="../vardef/testerinput/description">
        <td class="DefaultCell"><xsl:value-of select="testerinput/description" /></td>
      </xsl:if>
    </tr>
  </xsl:template>
  <xsl:template name="command-vardef">
    <tr>
      <td class="DefineCell"><xsl:value-of select="@timestamp"/></td>
      <td class="NumberCell"/>
      <td class="DefaultCell">
        <xsl:text>Variable definition</xsl:text>
        <table class="InfoTable">
          <tr>
            <td class="DefineCell">Name</td>
            <td class="DefineCell">Type</td>
            <td class="DefineCell">Value</td>
          </tr>
          <xsl:apply-templates select="vardef" mode="command"/>
        </table>
      </td>
      <td class="DefaultCell">-</td>
    </tr>
  </xsl:template>
  <xsl:template match="vardef" mode="command">
    <tr>
      <td class="DefaultCell"><xsl:value-of select="@name"/></td>
      <td class="DefaultCell"><xsl:value-of select="@type"/></td>
      <td class="DefaultCell"><xsl:value-of select="testerinput/inputvalue"/></td>
    </tr>
  </xsl:template>
  <!-- Template: System Variable Definition -->
  <xsl:template match="sysvardef">
    <tr valign="top">
      <td class="DefineCell">
        <xsl:if test="@namespace"><xsl:value-of select="@namespace"/><xsl:text>::</xsl:text></xsl:if>
        <xsl:value-of select="@name" />
      </td>
      <td class="DefaultCell"><xsl:value-of select="@type" /></td>
      <xsl:choose>
        <xsl:when test="value">
          <td class="DefaultCell"><xsl:value-of select="value"/></td>
        </xsl:when>
        <xsl:otherwise>
          <td class="DefaultCell"><xsl:value-of select="." /></td>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:choose>
        <xsl:when test="@min">
          <td class="DefaultCell"><xsl:value-of select="@min"/></td>
        </xsl:when>
        <xsl:otherwise>
          <td class="DefaultCell"><xsl:text>-</xsl:text></td>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:choose>
        <xsl:when test="@max">
          <td class="DefaultCell"><xsl:value-of select="@max"/></td>
        </xsl:when>
        <xsl:otherwise>
          <td class="DefaultCell"><xsl:text>-</xsl:text></td>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:choose>
        <xsl:when test="valuetable">
          <td class="DefaultCell"><xsl:apply-templates select="valuetable" mode="vardef"/></td>
        </xsl:when>
        <xsl:otherwise>
          <td class="DefaultCell"><xsl:text>-</xsl:text></td>
        </xsl:otherwise>
      </xsl:choose>
    </tr>
  </xsl:template>
  <!-- Template: Value Table -->
  <xsl:template match="valuetable" mode="vardef">
    <xsl:if test="enumerationvalue">
        <xsl:apply-templates select="enumerationvalue" mode="vardef"/>
    </xsl:if>
  </xsl:template>
  <!-- Template: Enumeration Value -->
  <xsl:template match="enumerationvalue" mode="vardef">
     <xsl:value-of select="@value"/><xsl:text> = </xsl:text><xsl:value-of select="@description"/>
     <br/>
  </xsl:template>

  <!-- Template: Image -->
  <xsl:template name="imagefile">
    <xsl:param name="file"/>
    <xsl:param name="width"/>
    <xsl:param name="height"/>
    <img src='{$file}'>
      <xsl:if test="string-length($width)>0">
        <xsl:attribute name="width"><xsl:value-of select="$width"/></xsl:attribute>
      </xsl:if>
      <xsl:if test="string-length($height)>0">
        <xsl:attribute name="height"><xsl:value-of select="$height"/></xsl:attribute>
      </xsl:if>
    </img>
  </xsl:template>
  <xsl:template match="image">
    <xsl:variable name="imagefilename">
      <xsl:choose>
        <!-- work around current limitations due to usage of subdirectories. Image paths given  -->
        <!-- explicitly by the user can be relative to the location of the XML report. Content  -->
        <!-- parts of this report (current output) are located in the the subdirectory          -->
        <!-- {$ReportPartsSubdir}, so we have to prepend '../' to have correct relative paths.  -->
        <xsl:when test='contains(@file, "://")'>
          <xsl:value-of select="@file"/>
        </xsl:when>
        <xsl:when test='starts-with(@file, "data:image/")'>
          <xsl:value-of select="@file"/>
        </xsl:when>
        <xsl:otherwise>
          <xsl:value-of select="$RootFolder"/>
          <xsl:value-of select="@file"/>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:choose>
      <xsl:when test="@width|@height">
        <a href='{$imagefilename}'>
          <xsl:if test="$LinkImageNewWindow=true()">
            <xsl:attribute name="target">_new</xsl:attribute>
          </xsl:if>
          <xsl:call-template name="imagefile">
            <xsl:with-param name="file"><xsl:value-of select="$imagefilename"/></xsl:with-param>
            <xsl:with-param name="width"><xsl:value-of select="@width"/></xsl:with-param>
            <xsl:with-param name="height"><xsl:value-of select="@height"/></xsl:with-param>
          </xsl:call-template>
        </a>
      </xsl:when>
      <xsl:otherwise>
        <xsl:call-template name="imagefile">
          <xsl:with-param name="file"><xsl:value-of select="$imagefilename"/></xsl:with-param>
          <xsl:with-param name="width"><xsl:value-of select="@width"/></xsl:with-param>
          <xsl:with-param name="height"><xsl:value-of select="@height"/></xsl:with-param>
        </xsl:call-template>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <!-- Template: Value -->
  <xsl:template match="value">
    <xsl:value-of select="@actual" />
    <xsl:text> (range: </xsl:text><xsl:value-of select="@min" />
    <xsl:text> - </xsl:text><xsl:value-of select="@max" /><xsl:text>)</xsl:text>
  </xsl:template>

  <!-- Template: Information -->
  <xsl:template match="info">
    <xsl:value-of select="name" /><xsl:text>: </xsl:text>
    <xsl:call-template name="replacelinebreak">
      <xsl:with-param name="srcnode">
        <xsl:value-of select="description" />
      </xsl:with-param>
    </xsl:call-template>
  </xsl:template>

  <!-- Template: CAN Message -->
  <xsl:template match="canmsg">
    <xsl:text>CAN message </xsl:text>
    <xsl:value-of select="@id" />
    <xsl:if test="@dlc">
      <xsl:text>, dlc = </xsl:text>
      <xsl:value-of select="@dlc" />
    </xsl:if>
    <xsl:if test="@rtr">
      <xsl:text>, </xsl:text>
      <xsl:value-of select="@rtr" />
    </xsl:if>
    <xsl:if test="byte">
      <xsl:text>, data bytes = </xsl:text>
      <xsl:for-each select="byte">
        <xsl:value-of select="." />
        <xsl:text> </xsl:text>
      </xsl:for-each>
    </xsl:if>
  </xsl:template>

  <!-- Template: MOST Message -->
  <xsl:template match="mostmsg">
    <xsl:text>MOST </xsl:text>
    <xsl:if test="@ams='ams'">
      <xsl:text>AMS </xsl:text>
    </xsl:if>
    <xsl:if test="@ams='ctrl'">
      <xsl:text>CMS </xsl:text>
    </xsl:if>
    <xsl:text>message </xsl:text>
    <xsl:choose>
    <xsl:when test="@name">
      <xsl:if test="@sa">
        <xsl:value-of select="@sa" /><xsl:text>.</xsl:text>
      </xsl:if>
      <xsl:if test="@da">
        <xsl:value-of select="@da" /><xsl:text>.</xsl:text>
      </xsl:if>
      <xsl:value-of select="@name" /><xsl:text> </xsl:text>
      <xsl:if test="byte">
      <xsl:text>, data bytes = </xsl:text>
      <xsl:for-each select="byte">
        <xsl:value-of select="." /><xsl:text> </xsl:text>
      </xsl:for-each>
      </xsl:if>
    </xsl:when>
    <xsl:otherwise>
      <xsl:if test="@fblock"><xsl:text> fblock = </xsl:text><xsl:value-of select="@fblock" /></xsl:if>
      <xsl:if test="@instance"><xsl:text>, instance = </xsl:text><xsl:value-of select="@instance" /></xsl:if>
      <xsl:if test="@function"><xsl:text>, function = </xsl:text><xsl:value-of select="@function" /></xsl:if>
      <xsl:if test="@optype"><xsl:text>, optype = </xsl:text><xsl:value-of select="@optype" /></xsl:if>
      <xsl:if test="@telid"><xsl:text>, telid = </xsl:text><xsl:value-of select="@telid" /></xsl:if>
      <xsl:if test="@tellen"><xsl:text>, tellen = </xsl:text><xsl:value-of select="@tellen" /></xsl:if>
      <xsl:if test="@sa"><xsl:text>, source = </xsl:text><xsl:value-of select="@sa" /></xsl:if>
      <xsl:if test="@da"><xsl:text>, destination = </xsl:text><xsl:value-of select="@da" /></xsl:if>
      <xsl:if test="byte">
      <xsl:text>, data bytes = </xsl:text>
      <xsl:for-each select="byte">
        <xsl:value-of select="." /><xsl:text> </xsl:text>
      </xsl:for-each>
      </xsl:if>
    </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <!-- Template: MOST System Message -->
  <xsl:template match="mostsysmsg">
    <xsl:text>MOST system message with rtype = </xsl:text><xsl:value-of select="@rtype" />
    <xsl:if test="@sa"><xsl:text>, source = </xsl:text><xsl:value-of select="@sa" /></xsl:if>
    <xsl:if test="@da"><xsl:text>, destination = </xsl:text><xsl:value-of select="@da" /></xsl:if>
    <xsl:if test="byte">
      <xsl:text>, data bytes = </xsl:text>
      <xsl:for-each select="byte">
        <xsl:value-of select="." /><xsl:text> </xsl:text>
      </xsl:for-each>
    </xsl:if>
  </xsl:template>

  <!-- Template: LIN Message -->
  <xsl:template match="linframe">
    <xsl:text>LIN frame </xsl:text>
    <xsl:value-of select="@id" />
    <xsl:if test="normalize-space(@channel)"><xsl:text>, LIN</xsl:text><xsl:value-of select="@channel" /></xsl:if>
    <xsl:if test="@dir"><xsl:text>, </xsl:text><xsl:value-of select="@dir" /></xsl:if>
    <xsl:if test="@dlc"><xsl:text>, dlc = </xsl:text><xsl:value-of select="@dlc" /></xsl:if>
    <xsl:if test="byte">
      <xsl:text>, data bytes = </xsl:text>
      <xsl:for-each select="byte">
        <xsl:value-of select="." /><xsl:text> </xsl:text>
      </xsl:for-each>
    </xsl:if>
  </xsl:template>

  <!-- Template: GMLAN Message -->
  <xsl:template match="gmlanmsg">
    <xsl:text>GMLan message </xsl:text>
    <xsl:value-of select="@id" />
    <xsl:if test="@sourceId"><xsl:text>, sourceId = </xsl:text><xsl:value-of select="@sourceId" /></xsl:if>
    <xsl:if test="@prio"><xsl:text>, prio = </xsl:text><xsl:value-of select="@prio" /></xsl:if>
    <xsl:if test="@dlc"><xsl:text>, dlc = </xsl:text><xsl:value-of select="@dlc" /></xsl:if>
    <xsl:if test="@rtr"><xsl:text>, </xsl:text><xsl:value-of select="@rtr" /></xsl:if>
    <xsl:if test="byte">
      <xsl:text>, data bytes = </xsl:text>
      <xsl:for-each select="byte">
        <xsl:value-of select="." /><xsl:text> </xsl:text>
      </xsl:for-each>
    </xsl:if>
  </xsl:template>

  <!-- Template: Test Pattern -->
  <xsl:template match="testpattern" mode="testcase">
    <xsl:param name="id"/>
    <xsl:call-template name="testpattern">
      <xsl:with-param name="id" select="$id"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="testpattern">
    <xsl:param name="id"/>
    <xsl:call-template name="testpattern">
      <xsl:with-param name="id" select="$id"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template name="testpattern">
    <xsl:param name="id"/>
    <!-- One level of indentation for each surrounding testpattern: -->
    <xsl:variable name="IndentLevel" select="count(ancestor::testpattern|ancestor::command)+1"/>
    <xsl:variable name="Indent" select="$IndentLevel*$IndentDepth"/>
    <xsl:variable name="BackgroundPatternClass">
      <xsl:choose>
        <xsl:when test="result/@result='pass'">PositiveResultBackground</xsl:when>
        <xsl:when test="result/@result='fail'">NegativeResultBackground</xsl:when>
        <xsl:when test="result/@result='warn'">WarningResultBackground</xsl:when>
        <xsl:when test="result/@result='skip'">DefaultTableBackground</xsl:when>
        <xsl:when test="result/@result='na'">DefaultTableBackground</xsl:when>
        <xsl:when test="result/@result='inconclusive'">InconclusiveResultBackground</xsl:when>
        <xsl:when test="result/@result='error'">ErrorResultBackground</xsl:when>
      </xsl:choose>
    </xsl:variable>
    <tr>
      <td class="PatternSeparator" colspan="4"/>
    </tr>
    <tr class="{$BackgroundPatternClass}">
      <td>
        <xsl:attribute name="style"><xsl:text>text-indent: </xsl:text><xsl:value-of select="$Indent"/><xsl:text>px;</xsl:text></xsl:attribute>
        <xsl:attribute name="class">ResultBlockHeading</xsl:attribute>
        <xsl:attribute name="colspan">4</xsl:attribute>
        <big class="Heading4">
          <xsl:number level="multiple" count="testpattern|command" />
          <xsl:text>. </xsl:text><xsl:value-of select="title" />
          <xsl:if test="description">
            <xsl:text> - </xsl:text><xsl:value-of select="description" />
          </xsl:if>
          <xsl:text>: </xsl:text>
          <xsl:choose>
            <xsl:when test="result/@result='pass'">Passed</xsl:when>
            <xsl:when test="result/@result='fail'">Failed</xsl:when>
            <xsl:when test="result/@result='skip'">Skipped</xsl:when>
            <xsl:when test="result/@result='inconclusive'">Inconclusive</xsl:when>
            <xsl:when test="result/@result='error'">Error in test system</xsl:when>
            <xsl:when test="result/@result='na'">NA</xsl:when>
            <xsl:when test="result/@result='warn'">Passed with Warning: </xsl:when>
          </xsl:choose>
        </big>
      </td>
    </tr>

    <xsl:if test="not(result/@result='skip')">
      <!-- Add information about teststeps, details and violations -->
      <xsl:if test="testpattern">
        <tr>
          <td>
            <xsl:attribute name="style"><xsl:text>text-indent: </xsl:text><xsl:value-of select="$Indent"/><xsl:text>px;</xsl:text></xsl:attribute>
            <xsl:attribute name="class">DefineCell</xsl:attribute>
            <xsl:attribute name="nowrap">nowrap</xsl:attribute>
            <xsl:call-template name="showTimeStampImpl">
              <xsl:with-param name="timeStampValue" select="@timestamp"/>
            </xsl:call-template>
          </td>
          <td class="DefaultCell"></td>
          <xsl:choose>
            <xsl:when test="@type='testpattern'">
              <td class="DefaultCell">Test pattern begin</td>
            </xsl:when>
            <xsl:when test="@type='testprimitive'">
              <td class="DefaultCell">Test primitive begin</td>
            </xsl:when>
            <xsl:when test="@type='controlfunction'">
              <td class="DefaultCell">Control function begin</td>
            </xsl:when>
            <xsl:otherwise>
              <td class="DefaultCell">Test pattern begin</td>
            </xsl:otherwise>
          </xsl:choose>
          <td class="DefaultCell">-</td>
        </tr>
      </xsl:if>

      <xsl:if test="vardef">
        <xsl:call-template name="command-vardef"/>
      </xsl:if>
      <xsl:apply-templates select="teststep|testpattern|details|violation|comment|command|checkbegin|checkend|checkstartupinfo|checkterminationinfo" mode="testcase">
        <xsl:with-param name="id" select="$id"/>
      </xsl:apply-templates>
      <xsl:if test="testpattern">
        <tr>
          <td>
            <xsl:attribute name="style"><xsl:text>text-indent: </xsl:text><xsl:value-of select="$Indent"/><xsl:text>px;</xsl:text></xsl:attribute>
            <xsl:attribute name="class">DefineCell</xsl:attribute>
            <xsl:attribute name="nowrap">nowrap</xsl:attribute>
            <xsl:call-template name="showTimeStampImpl">
                <xsl:with-param name="timeStampValue" select="result/@timestamp"/>
            </xsl:call-template>
          </td>
          <td class="DefaultCell"></td>
          <xsl:choose>
            <xsl:when test="@type='testpattern'">
              <td class="DefaultCell">Test pattern end</td>
            </xsl:when>
            <xsl:when test="@type='testprimitive'">
              <td class="DefaultCell">Test primitive end</td>
            </xsl:when>
            <xsl:when test="@type='controlfunction'">
              <td class="DefaultCell">Control function end</td>
            </xsl:when>
            <xsl:otherwise>
              <td class="DefaultCell">Test pattern end</td>
            </xsl:otherwise>
          </xsl:choose>
          <td class="DefaultCell">-</td>
        </tr>
      </xsl:if>
      <tr><td class="PatternSeparator" colspan="4"></td></tr>
    </xsl:if>
  </xsl:template>

  <!--
    Hint for linking the violation and checkstatistic elements: XPath for all checkstatistic elements on the violation/checkstatistic
    ancestor axis until the topmost statistic at the level where the check is created:
      ancestor::*[local-name()='testcase' or local-name()='testgroup' or local-name()='testmodule' or local-name()='testsequence' or local-name()='testunit']/checkstatistic[@id=current()/@id]
    simplified
      ancestor::*/checkstatistic[@id=current()/@id]
    The order in result node set starts from template context to the root element:
      [position()=last()]    = statistic at the level where is created
      [1]                    = statistic element at the next upper level where the violation occurs
                             = template context = checkstatistc itself
    WORX: the order is valid for Sablotron, Xalan, libxsltproc - for other engines the order could be same as document order!
  -->
  <xsl:template match="violation" mode="link2statistic">
    <xsl:choose>
      <xsl:when test="$CheckStatisticUpLinks=true()">
        <!-- select checkstatistic on level of violation: [1] -->
        <xsl:variable name="mystatistic" select="(ancestor::*/checkstatistic[@id=current()/@checkId])[1]"/>
        <xsl:choose>
          <xsl:when test="$mystatistic/node()">
            <a>
              <xsl:attribute name="href">
                <!-- link to the correct frame file: -->
                <xsl:call-template name="showUpperStatisticImpl">
                  <xsl:with-param name="statisticNodeSet" select="$mystatistic"/>
                </xsl:call-template>
              </xsl:attribute>
              <xsl:value-of select="@checkTitle"/>
              <xsl:text> (</xsl:text>
              <xsl:apply-templates select="$mystatistic" mode="checkidentifier"/>
              <xsl:text>)</xsl:text>
            </a>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="@checkTitle"/>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="@checkTitle"/>
      </xsl:otherwise>
    </xsl:choose>
    <xsl:text>: </xsl:text>
  </xsl:template>
  <xsl:template match="violation[not(@checkId)]" mode="link2statistic"/>

  <!-- Template: Table with check statistics -->
  <xsl:template match="checkstatistic" mode="report">
    <xsl:if test="@result='fail'">
	<div class="Heading4"><xsl:text>Test Case Check Statistics</xsl:text></div>
		<div class="Indentation">
		  <!-- Check statistics heading -->
		  <xsl:variable name="BackgroundClass">
			<xsl:choose>
			  <xsl:when test="@result='fail'">NegativeResultBackground</xsl:when>
			  <xsl:when test="@result='inconclusive'">InconclusiveResultBackground</xsl:when>
			  <xsl:when test="@result='error'">ErrorResultBackground</xsl:when>
			  <xsl:when test="@result='none'">NoneResultCell</xsl:when>
			  <xsl:otherwise>PositiveResultBackground</xsl:otherwise>
			</xsl:choose>
		  </xsl:variable>
		  <table class='{$BackgroundClass}'>
			<tr>
			  <td>
				<big class="Heading4">
				  <xsl:choose>
					<xsl:when test="$CheckStatisticUpLinks=true() and @id != ''"> <!-- avoid making erroneous links when no id is given (broken checkstatistics produced on queue overflow) -->
					  <a>
						<xsl:attribute name="name">
						  <xsl:apply-templates select="." mode="checkstatistic-anchor"/>
						</xsl:attribute>
						<xsl:value-of select="@checkname"/>
					  </a>
					  <xsl:text> (</xsl:text>
					  <xsl:apply-templates select="." mode="checkidentifier"/>
					  <xsl:variable name="upperStatistic" select="(ancestor::*/checkstatistic[@id=current()/@id])[2]"/> <!-- use checkstatistic one level up [2], not self [1] -->
					  <xsl:if test="$upperStatistic">
						<xsl:text> </xsl:text>
						<a>
						  <xsl:attribute name="href">
							<xsl:call-template name="showUpperStatisticImpl">
							  <xsl:with-param name="statisticNodeSet" select="$upperStatistic"/>
							</xsl:call-template>
						  </xsl:attribute>
						  <xsl:text>up</xsl:text>
						</a>
					  </xsl:if>
					  <xsl:text>): </xsl:text>
					</xsl:when>
					<xsl:otherwise>
					  <xsl:value-of select="@checkname"/><xsl:text>: </xsl:text>
					</xsl:otherwise>
				  </xsl:choose>
				  <xsl:apply-templates select="." mode="result"/>
				</big>
			  </td>
			</tr>
		  </table>

		  <div class="Indentation">
		  <!-- Check statistics table -->
		  <xsl:if test="spec">
			<table class="CheckStatisticsTable">
			  <tr>
				<th class="TableHeadingCell" colspan="2">Parameters</th>
				<th/>
			  </tr>
			  <xsl:for-each select="spec/xinfo">
				<tr>
				  <td class="DefineCell">
					<xsl:value-of select="name" />
				  </td>
				  <td class="DefaultCell">
					<xsl:value-of select="description" />
				  </td>
				</tr>
			  </xsl:for-each>
			</table>
		  </xsl:if>
		  <xsl:for-each select="statistic">
			<xsl:variable name="StatisticsTitle">
			  <xsl:choose>
				<xsl:when test="@title"><xsl:value-of select="@title"/></xsl:when>
				<xsl:otherwise><xsl:text>Statistics</xsl:text></xsl:otherwise>
			  </xsl:choose>
			</xsl:variable>
			<xsl:variable name="nValues" select="count(xinfo)"/>
			<xsl:choose>
			  <xsl:when test="@type='distribution'">
				<table class="CheckStatisticsTable">
				<!-- output xinfo elements as values in horizontal distribution table -->
				  <tr>
					<th class="TableHeadingCell" colspan='{$nValues}'><xsl:value-of select="$StatisticsTitle"/></th>
				  </tr>
				  <tr>
					<xsl:for-each select="xinfo">
					  <td class="DefineCell">
						<xsl:value-of select="name" />
					  </td>
					</xsl:for-each>
				  </tr>
				  <tr>
					<xsl:for-each select="xinfo">
					  <td class="DefaultCell">
						<xsl:value-of select="description" />
					  </td>
					</xsl:for-each>
				  </tr>
				</table>
			  </xsl:when>
			  <xsl:otherwise>
				<!-- output xinfo elements as independent values in normal (vertical) table -->
				<table class="CheckStatisticsTable">
				  <tr>
					<th class="TableHeadingCell" colspan="2">
					  <xsl:value-of select="$StatisticsTitle"/>
					</th>
				  </tr>
				  <xsl:for-each select="xinfo">
					<tr>
					  <td class="DefineCell">
						<xsl:value-of select="name" />
					  </td>
					  <td class="DefaultCell">
						<xsl:value-of select="description" />
					  </td>
					</tr>
				  </xsl:for-each>
				</table>
			  </xsl:otherwise>
			</xsl:choose>
		  </xsl:for-each>
		  <table class="DefaultTable">
			<tr>
			  <td class="PatternSeparator"/>
			</tr>
		  </table>
		  </div>
		</div>
	</xsl:if>
  </xsl:template>

  <xsl:template match="checkstatistic[@result='pass']" mode="result">
    <xsl:text>Check passed</xsl:text>
  </xsl:template>
  <xsl:template match="checkstatistic[@result='fail']" mode="result">
    <xsl:text>Check failed</xsl:text>
  </xsl:template>
  <xsl:template match="checkstatistic[@result='error']" mode="result">
    <xsl:text>Check finished with error in test system</xsl:text>
  </xsl:template>
  <xsl:template match="checkstatistic[@result='inconclusive']" mode="result">
    <xsl:text>Check inconclusive</xsl:text>
  </xsl:template>
  <xsl:template match="checkstatistic[@result='none']" mode="result">
    <xsl:text>Check finished without verdict</xsl:text>
  </xsl:template>
  <xsl:template match="checkstatistic" mode="result">
    <xsl:text>Check </xsl:text>
    <xsl:value-of select="@result"/>
  </xsl:template>


  <!--
    produces a unique anchor name for the checkstatistic, based on check-id and hierarchic position of the statistic
    e.g. "48_10001_1.2.1"
  -->
  <xsl:template match="checkstatistic|checkbegin|checkstartupinfo|checkend|checkterminationinfo" mode="checkstatistic-anchor">
    <xsl:value-of select="@id"/><xsl:text>_</xsl:text>
    <xsl:apply-templates select="." mode="checkstatistic-hierarchicnumber"/>
  </xsl:template>

  <!--
    produces hierarchic number for position of checkstatistic
    e.g. "1.2.1", empty for checkstatistic on testmodule|testunit level
  -->
  <xsl:template match="checkstatistic|checkbegin|checkstartupinfo|checkend|checkterminationinfo" mode="checkstatistic-hierarchicnumber">
    <xsl:choose>
      <xsl:when test="parent::testmodule or parent::testunit">
        <xsl:text></xsl:text>
      </xsl:when>
      <xsl:otherwise>
        <xsl:number level="multiple" count="testcase|testgroup|testfixture|testsequence"/>
        <!-- WORX: sablotron returns "1" for the checkstatistic on testmodule or testunit level here, not ""! -->
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <!--
    produces identifier for setup of corresponding check (corresponds to topmost checkstatistic)
    e.g. "1.1#2", "#3" (testmodule or testunit level)
  -->
  <xsl:template match="checkstatistic" mode="checkidentifier">
    <xsl:variable name="topmost-checkstatistic" select="key('csSetupNodes', @id)"/>
    <xsl:apply-templates select="$topmost-checkstatistic" mode="checkstatistic-hierarchicnumber"/>
    <xsl:text>#</xsl:text>
    <xsl:apply-templates select="$topmost-checkstatistic" mode="setupPosition"/>
  </xsl:template>

  <!--
    Calculates the local "setup position" for the context checkstatistic node, i.e. its position in the list of siblings
    which have no parent checkstatistic (these are the checks which were set up in the current context, not in a parent testgroup.
  -->
  <xsl:template match="checkstatistic" mode="setupPosition">
    <xsl:value-of select="key('csSetupNodes', @id)/@seq"/>
  </xsl:template>

  <!-- writes the hierarchical number of the test group/case where the corresponding check was created -->
  <xsl:template match="checkstatistic" mode="setupContext">
    <xsl:variable name="parentStatistic" select="../../checkstatistic[@id=current()/@id]"/>
    <xsl:choose>
      <xsl:when test="$parentStatistic">
        <xsl:apply-templates select="$parentStatistic" mode="setupContext"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:if test="not(parent::testmodule) and not(parent::testunit)">
          <xsl:number level="multiple" count="testcase|testgroup|testfixture|testcycle|testsequence"/>
          <!-- caution: sablotron returns "1" for the checkstatistic on testmodule or testunit level here, not ""! -->
        </xsl:if>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  <xsl:template name="checkstatistic-heading">
		<div class="Heading4">Test Module Check Statistics</div>
  </xsl:template>

  <xsl:template match="checkbegin|checkstartupinfo">
    <xsl:call-template name="checkstartup"/>
  </xsl:template>
  <xsl:template match="checkbegin|checkstartupinfo" mode="head">
    <xsl:param name="id"/>
    <xsl:call-template name="checkstartup-head">
      <xsl:with-param name="id" select="$id"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="checkbegin|checkstartupinfo" mode="tail">
    <xsl:call-template name="checkstartup"/>
  </xsl:template>
  <xsl:template match="checkbegin|checkstartupinfo" mode="testcase">
    <xsl:call-template name="checkstartup"/>
  </xsl:template>
  <!-- Template: checkbegin/checkstartupinfo reported as a step with link to the corresponding checkstatistic -->
  <xsl:template name="checkstartup">
    <tr>
      <xsl:if test="@result='fail' or @result='warn' or @result='error' or @result='inconclusive'">
        <xsl:attribute name="id">
          <xsl:value-of select="generate-id(.)"/>
        </xsl:attribute>
      </xsl:if>
      <td class="DefineCell"><xsl:value-of select="@timestamp"/></td>
      <td class="DefaultCell"/>
      <td class="DefaultCell">
        <xsl:choose>
          <xsl:when test="$CheckStatisticUpLinks=true() and @id != ''">
            <xsl:variable name="checkstatistic" select="key('csSetupNodes', @id)"/>
            <xsl:choose>
              <xsl:when test="local-name()='checkbegin' and $checkstatistic/node()">
                <a>
                  <xsl:attribute name="name">
                    <xsl:text>checkbegin_</xsl:text>
                    <xsl:value-of select="@id"/>
                  </xsl:attribute>
                  <xsl:attribute name="href">
                    <xsl:call-template name="showUpperStatisticImpl">
                      <xsl:with-param name="statisticNodeSet" select="$checkstatistic"/>
                    </xsl:call-template>
                  </xsl:attribute>
                  <xsl:value-of select="@checkname"/>
                  <xsl:text> (</xsl:text>
                  <xsl:apply-templates select="$checkstatistic" mode="checkidentifier"/>
                  <xsl:text>)</xsl:text>
                </a>
              </xsl:when>
              <xsl:otherwise>
                <xsl:value-of select="@checkname"/>
              </xsl:otherwise>
            </xsl:choose>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="@checkname"/>
          </xsl:otherwise>
        </xsl:choose>
        <xsl:text>: </xsl:text>
        <xsl:choose>
          <xsl:when test="local-name()='checkstartupinfo'">
            <xsl:value-of select="."/>
          </xsl:when>
          <xsl:otherwise>
            <xsl:text>Start</xsl:text>
          </xsl:otherwise>
        </xsl:choose>
      </td>
      <xsl:choose>
        <xsl:when test="local-name()='checkstartupinfo'">
          <xsl:choose>
            <xsl:when test="@result='pass'">
            <td class="PositiveResultCell"><xsl:text>pass</xsl:text></td>
            </xsl:when>
            <xsl:when test="@result='fail'">
            <td class="NegativeResultCell"><xsl:text>fail</xsl:text></td>
            </xsl:when>
            <xsl:when test="@result='warn'">
            <td class="WarningCell"><xsl:text>warning</xsl:text></td>
            </xsl:when>
            <xsl:when test="@result='inconclusive'">
            <td class="InconclusiveResultCell"><xsl:text>inconclusive</xsl:text></td>
            </xsl:when>
            <xsl:when test="@result='error'">
            <td class="ErrorResultCell"><xsl:text>error in test system</xsl:text></td>
            </xsl:when>
            <xsl:otherwise>
            <td class="DefaultCell"/>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:when>
        <xsl:otherwise>
          <td class="DefaultCell"/>
        </xsl:otherwise>
      </xsl:choose>
    </tr>
  </xsl:template>
  <xsl:template name="checkstartup-head">
    <xsl:param name="id"/>
    <xsl:apply-templates select="." mode="link-up"/>
    <div id="{$DivPrefix}{$id}">
      <table class="TestGroupHeadingBackground">
        <tr>
          <td>
            <big class="Heading3">
              <xsl:text>Startup of checks</xsl:text>
            </big>
          </td>
        </tr>
      </table>
      <div class="Indentation">
        <table class="ResultTable">
          <xsl:call-template name="teststep-header"/>
          <xsl:apply-templates select=".|following-sibling::checkbegin|following-sibling::checkstartupinfo" mode="tail"/>
        </table>
      </div>
    </div>
  </xsl:template>
  <xsl:template match="checkend|checkterminationinfo" mode="head">
    <xsl:param name="id"/>
    <xsl:apply-templates select="." mode="link-up"/>
    <xsl:call-template name="checktermination-head">
      <xsl:with-param name="id" select="$id"/>
    </xsl:call-template>
  </xsl:template>
  <xsl:template match="checkend|checkterminationinfo" mode="tail">
    <xsl:call-template name="checktermination"/>
  </xsl:template>
  <xsl:template name="checktermination">
    <tr>
      <xsl:if test="@result='fail' or @result='warn' or @result='error' or @result='inconclusive'">
        <xsl:attribute name="id">
          <xsl:value-of select="generate-id(.)"/>
        </xsl:attribute>
      </xsl:if>
      <td class="DefineCell"><xsl:value-of select="@timestamp"/></td>
      <td class="DefaultCell"/>
      <td class="DefaultCell">
        <xsl:choose>
          <xsl:when test="$CheckStatisticUpLinks=true() and @id != ''">
            <xsl:variable name="checkstatistic" select="key('csSetupNodes', @id)"/>
            <xsl:variable name="checkbegin" select="key('checkBeginNodes', @id)"/>
            <xsl:choose>
              <xsl:when test="local-name()='checkend' and $checkbegin and $checkstatistic">
                <a>
                  <xsl:attribute name="href">
                    <xsl:apply-templates select="$checkbegin" mode="href-file"/>
                    <xsl:text>#checkbegin_</xsl:text>
                    <xsl:value-of select="@id"/>
                  </xsl:attribute>
                  <xsl:value-of select="@checkname"/>
                  <xsl:text> (</xsl:text>
                  <xsl:apply-templates select="$checkstatistic" mode="checkidentifier"/>
                  <xsl:text>)</xsl:text>
                </a>
              </xsl:when>
              <xsl:otherwise>
                <xsl:choose>
                  <xsl:when test="$checkstatistic">
                    <a>
                      <xsl:attribute name="href">
                        <xsl:call-template name="showUpperStatisticImpl">
                          <xsl:with-param name="statisticNodeSet" select="$checkstatistic"/>
                        </xsl:call-template>
                      </xsl:attribute>
                      <xsl:value-of select="@checkname"/>
                      <xsl:text> (</xsl:text>
                      <xsl:apply-templates select="$checkstatistic" mode="checkidentifier"/>
                      <xsl:text>)</xsl:text>
                    </a>
                  </xsl:when>
                  <xsl:otherwise>
                    <xsl:value-of select="@checkname"/>
                  </xsl:otherwise>
                </xsl:choose>
              </xsl:otherwise>
            </xsl:choose>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="@checkname"/>
          </xsl:otherwise>
        </xsl:choose>
        <xsl:text>: </xsl:text>
        <xsl:choose>
          <xsl:when test="local-name()='checkterminationinfo'">
            <xsl:value-of select="."/>
          </xsl:when>
          <xsl:otherwise>
            <xsl:text>End</xsl:text>
          </xsl:otherwise>
        </xsl:choose>
      </td>
      <xsl:choose>
        <xsl:when test="local-name()='checkterminationinfo'">
          <xsl:choose>
            <xsl:when test="@result='pass'">
            <td class="PositiveResultCell"><xsl:text>pass</xsl:text></td>
            </xsl:when>
            <xsl:when test="@result='fail'">
            <td class="NegativeResultCell"><xsl:text>fail</xsl:text></td>
            </xsl:when>
            <xsl:when test="@result='warn'">
            <td class="WarningCell"><xsl:text>warning</xsl:text></td>
            </xsl:when>
            <xsl:when test="@result='inconclusive'">
            <td class="InconclusiveResultCell"><xsl:text>inconclusive</xsl:text></td>
            </xsl:when>
            <xsl:when test="@result='error'">
            <td class="ErrorResultCell"><xsl:text>error in test system</xsl:text></td>
            </xsl:when>
            <xsl:otherwise>
            <td class="DefaultCell"/>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:when>
        <xsl:otherwise>
          <td class="DefaultCell"/>
        </xsl:otherwise>
      </xsl:choose>
    </tr>
  </xsl:template>
  <xsl:template name="checktermination-head">
    <xsl:param name="id"/>
    <div id="{$DivPrefix}{$id}">
      <table class="TestGroupHeadingBackground">
        <tr>
          <td>
            <big class="Heading3">
              <xsl:text>Termination of checks</xsl:text>
            </big>
          </td>
        </tr>
      </table>
      <div class="Indentation">
        <table class="ResultTable">
          <xsl:call-template name="teststep-header"/>
          <xsl:apply-templates select=".|following-sibling::checkend|following-sibling::checkterminationinfo" mode="tail"/>
        </table>
      </div>
    </div>
  </xsl:template>
  <!-- Template: checkend reported as a step with link to the corresponding checkbegin or checkstatistic -->
  <xsl:template match="checkend|checkterminationinfo">
    <xsl:apply-templates select="." mode="testcase"/>
  </xsl:template>
  <xsl:template match="checkend|checkterminationinfo" mode="testcase">
    <xsl:call-template name="checktermination"/>
  </xsl:template>

  <!-- Templates for line break replacement \n => <br/> -->
  <xsl:template name="replacelinebreak">
    <xsl:param name="srcnode"/>
    <xsl:apply-templates select="$srcnode/child::* | $srcnode/text()" mode="replacelinebreak"/>
  </xsl:template>
  <xsl:template name="replacetextlinebreak">
    <xsl:param name="text" />
    <xsl:choose>
      <xsl:when test="$DoLinebreakTransformation=true()">
        <xsl:call-template name="replace-linebreak">
          <xsl:with-param name="text" select="$text"/>
        </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="$text" />
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  <xsl:template name="replace-linebreak">
    <xsl:param name="text"/>
    <xsl:variable name="len" select="string-length($text)"/>
    <xsl:choose>
      <xsl:when test="$len > 3">
        <xsl:variable name="mid" select="round($len div 2)"/>
        <!-- calculates the slice position -->
        <xsl:variable name="left-len">
          <xsl:choose>
            <!-- adjust the position when the slice point hits the '\\n' string  -->
            <xsl:when test="substring($text, $mid, 3)='\\n'">
              <xsl:value-of select="$mid - 1"/>
            </xsl:when>
            <!-- adjust the position when the slice point hits the '\n' string  -->
            <xsl:when test="substring($text, $mid, 2)='\n'">
              <xsl:choose>
                <!-- adjust the position further if '\\n' was found -->
                <xsl:when test="substring($text, $mid - 1, 3)='\\n'">
                  <xsl:value-of select="$mid - 2"/>
                </xsl:when>
                <xsl:otherwise>
                  <xsl:value-of select="$mid - 1"/>
                </xsl:otherwise>
              </xsl:choose>
            </xsl:when>
            <xsl:otherwise>
              <xsl:value-of select="$mid"/>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:variable>

        <xsl:variable name="left-part" select="substring($text, 1, $left-len)"/>
        <xsl:variable name="right-part" select="substring($text, $left-len + 1, $len - $left-len)"/>

        <xsl:variable name="left">
          <xsl:call-template name="replace-linebreak-part">
            <xsl:with-param name="text" select="$left-part"/>
          </xsl:call-template>
        </xsl:variable>

        <xsl:variable name="right">
          <xsl:call-template name="replace-linebreak-part">
            <xsl:with-param name="text" select="$right-part"/>
          </xsl:call-template>
        </xsl:variable>

        <!-- join the two processed parts -->
        <xsl:copy-of select="$left"/>
        <xsl:copy-of select="$right"/>
      </xsl:when>
      <xsl:when test="$text='\\n'">
        <xsl:text>\n</xsl:text>
      </xsl:when>
      <xsl:when test="contains($text, '\n')">
        <xsl:value-of select="substring-before($text, '\n')"/>
        <br/>
        <xsl:value-of select="substring-after($text, '\n')"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:copy-of select="$text"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <!-- replace in the sliced string the '\n' or '\\n' with <br> and '\n' respectively  -->
  <xsl:template name="replace-linebreak-part">
    <xsl:param name="text"/>
    <xsl:choose>
      <xsl:when test="contains($text, '\n')">
        <xsl:choose>
          <xsl:when test="not(contains(substring-after($text, '\n'), '\n'))">
            <xsl:variable name="before" select="substring-before($text, '\n')"/>
            <xsl:variable name="after" select="substring-after($text, '\n')"/>
            <xsl:value-of select="$before"/>
            <xsl:choose>
              <xsl:when test="string-length($before)=0">
                <br/>
              </xsl:when>
              <xsl:when test="substring($before, string-length($before), 1) = '\'">
                <xsl:text>n</xsl:text>
              </xsl:when>
              <xsl:otherwise>
                <br/>
              </xsl:otherwise>
            </xsl:choose>
            <xsl:value-of select="$after"/>
          </xsl:when>
          <xsl:otherwise>
            <xsl:call-template name="replace-linebreak">
              <xsl:with-param name="text" select="$text"/>
            </xsl:call-template>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:when>
      <xsl:otherwise>
        <xsl:copy-of select="$text"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="text()" mode="replacelinebreak" priority="2">
    <xsl:choose>
      <xsl:when test="contains(., '\n')">
    <xsl:call-template name="replacetextlinebreak">
          <xsl:with-param name="text">
            <xsl:value-of select="."/>
          </xsl:with-param>
    </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="."/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  <xsl:template match="node()" mode="replacelinebreak">
    <xsl:element name="{name()}">
      <xsl:for-each select="@*">
        <xsl:attribute name="{name()}"><xsl:value-of select="."/></xsl:attribute>
      </xsl:for-each>
      <xsl:apply-templates select="child::*|text()" mode="replacelinebreak"/>
    </xsl:element>
  </xsl:template>

  <xsl:template match="sut">
    <xsl:if test="info">
      <div class="Heading4"><xsl:text>System Under Test</xsl:text></div>
      <div class="Indentation">
        <table>
          <xsl:apply-templates select="info" mode="table"/>
        </table>
      </div>
    </xsl:if>
  </xsl:template>

  <xsl:template match="engineer">
    <xsl:if test="xinfo|info">
      <xsl:apply-templates select="." mode="title"/>
      <div class="Indentation">
        <table>
          <xsl:apply-templates select="xinfo" mode="table"/>
          <xsl:apply-templates select="info" mode="table"/>
        </table>
      </div>
    </xsl:if>
  </xsl:template>

  <xsl:template match="testsetup">
    <xsl:if test="xinfo|info">
      <div class="Heading4"><xsl:text>Test Setup</xsl:text></div>
        <div class="Indentation">
        <table>
        <xsl:apply-templates select="xinfo" mode="table"/>
        <xsl:apply-templates select="info" mode="table"/>
        </table>
        </div>
    </xsl:if>
  </xsl:template>

  <xsl:template match="hardware">
    <xsl:if test="position()=1">
      <div class="Heading4">Hardware</div>
    </xsl:if>
    <div class="Indentation">
      <div class="Heading4"><xsl:value-of select="@name" /></div>
      <div class="Indentation">
        <!-- show section comment -->
        <xsl:if test="sectioncomment">
          <xsl:value-of select="sectioncomment"></xsl:value-of>
          <br/><br/>
        </xsl:if>
        <table>
          <tr>
            <xsl:apply-templates select="xinfoset/xinfoobject[1]" mode="hardware-heading"/>
          </tr>
          <xsl:apply-templates select="xinfoset/xinfoobject" mode="hardware-detail"/>
        </table>
      </div>
    </div>
  </xsl:template>

  <xsl:template match="xinfoobject" mode="hardware-heading">
    <xsl:for-each select="xinfo">
      <th class="TableHeadingCell">
        <xsl:value-of select="name"/>
      </th>
    </xsl:for-each>
  </xsl:template>

  <xsl:template match="xinfoobject" mode="hardware-detail">
    <tr>
      <xsl:apply-templates select="xinfo" mode="hardware-detail"/>
    </tr>
  </xsl:template>

  <xsl:template match="xinfo" mode="hardware-detail">
    <td class="NumberCell">
      <xsl:value-of select="description"/>
    </td>
  </xsl:template>

  <xsl:template match="testlogfiles">
    <xsl:if test="testlogfile[@file[string-length(.)>0]]">
      <div class="Heading4"><xsl:text>Logging and video recordings</xsl:text></div>
      <div class="Indentation">
        <table>
          <th class="TableHeadingCell">Start Time</th>
          <th class="TableHeadingCell">End Time</th>
          <th class="TableHeadingCell">Logging/Video File</th>
          <xsl:for-each select="testlogfile">
            <tr>
              <td class="NumberCell"><xsl:value-of select="@logbegin"/></td>
              <td class="NumberCell"><xsl:value-of select="@logend"/></td>
              <td class="NumberCell" style="text-align:left"><xsl:value-of select="@file"/></td>
            </tr>
          </xsl:for-each>
        </table>
      </div>
    </xsl:if>
  </xsl:template>

  <xsl:template match="info|xinfo" mode="table">
    <tr>
      <td class="CellNoColor">
        <xsl:value-of select="name" />
        <xsl:text>: </xsl:text>
      </td>
      <td class="CellNoColor">
        <xsl:apply-templates select="description"/>
      </td>
    </tr>
  </xsl:template>

  <xsl:template match="description" mode="paragraph">
    <p>
      <xsl:apply-templates select="."/>
    </p>
  </xsl:template>

  <xsl:template match="description">
    <xsl:call-template name="replacelinebreak">
      <xsl:with-param name="srcnode">
        <xsl:value-of select="." />
      </xsl:with-param>
    </xsl:call-template>
  </xsl:template>

  <xsl:template match="testcycle" mode="overview">
    <tr>
      <td class="DefineCell" colspan="{$OverviewColumnCount}">
        <xsl:call-template name="aHrefImpl">
          <xsl:with-param name="externalID" select="current()"/>
          <xsl:with-param name="externalFile">
            <xsl:apply-templates select="." mode="html-name"/>
          </xsl:with-param>
          <xsl:with-param name="anchorText">
            <xsl:apply-templates select="." mode="heading-title"/>
          </xsl:with-param>
        </xsl:call-template>
      </td>
    </tr>
    <xsl:apply-templates select="preparation" mode="overview"/>
    <xsl:apply-templates select="testunit|testgroup|testcase|skipped" mode="overview"/>
    <xsl:apply-templates select="completion" mode="overview"/>
  </xsl:template>

  <xsl:template match="preparation" mode="overview">
    <tr>
      <td class="DefineCell" colspan="{$OverviewColumnCount}">
        <xsl:call-template name="aHrefImpl">
          <xsl:with-param name="externalID" select="."/>
          <xsl:with-param name="externalFile">
            <xsl:apply-templates select="." mode="html-name"/>
          </xsl:with-param>
          <xsl:with-param name="anchorText" select="'Preparation of Test Module'"/>
        </xsl:call-template>
      </td>
    </tr>
  </xsl:template>

  <xsl:template match="completion" mode="overview">
    <tr>
      <td class="DefineCell" colspan="{$OverviewColumnCount}">
        <xsl:call-template name="aHrefImpl">
          <xsl:with-param name="externalID" select="."/>
          <xsl:with-param name="externalFile">
            <xsl:apply-templates select="." mode="html-name"/>
          </xsl:with-param>
          <xsl:with-param name="anchorText" select="'Completion of Test Module'"/>
        </xsl:call-template>
      </td>
    </tr>
  </xsl:template>

  <xsl:template match="checkstatistic" mode="heading">
    <div class="Heading4">
      <xsl:text>Test </xsl:text>
      <xsl:choose>
        <xsl:when test="parent::testcase">Case</xsl:when>
        <xsl:when test="parent::testgroup">Group</xsl:when>
        <xsl:when test="parent::testfixture">Fixture</xsl:when>
        <xsl:when test="parent::testsequence">Sequence</xsl:when>
        <xsl:when test="parent::testunit">Unit</xsl:when>
      </xsl:choose>
      <xsl:text> Check Statistics</xsl:text>
    </div>
  </xsl:template>

  <xsl:template name="link-children">
    <xsl:param name="parent-nr" select="''"/>
    <xsl:param name="start-nr" select="0"/>
    <xsl:variable name="nodeset" select="/testreport|testunit|testcycle|preparation|completion|(checkbegin|checkstartupinfo)[1]|(checkend|checkterminationinfo)[1]|testgroup|testcase|testsequence|testcaselist|testsequencelist|testfixture"/>
    <xsl:if test="$nodeset">
      <div class="Indentation">
        <div class="Heading4">Contents</div>
        <div class="Indentation">
          <table>
            <xsl:apply-templates select="$nodeset" mode="link-child">
              <xsl:with-param name="parent-nr" select="$parent-nr"/>
              <xsl:with-param name="start-nr" select="$start-nr"/>
            </xsl:apply-templates>
          </table>
        </div>
      </div>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcycle" mode="link-child">
    <tr>
      <td class="DefaultCell"/>
      <td class="DefaultCell">
        <a>
          <xsl:attribute name="href">
            <xsl:apply-templates select="." mode="href-file"/>
           </xsl:attribute>
          <xsl:apply-templates select="." mode="name"/>
          <xsl:text> </xsl:text>
          <xsl:value-of select="@run"/>
        </a>
      </td>
    </tr>
  </xsl:template>
  <xsl:template match="testgroup" mode="link-child">
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
    <xsl:if test="descendant::testcase|descendant::testsequence|descendant::testsequencelist|descendant::testcaselist|descendant::testfixture">
      <tr>
        <td class="DefaultCell">
          <xsl:value-of select="$nr"/>
        </td>
        <td class="DefaultCell">
          <a>
            <xsl:attribute name="href">
              <xsl:apply-templates select="." mode="href-file"/>
            </xsl:attribute>
            <xsl:value-of select="./title"/>
          </a>
        </td>
      </tr>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcase" mode="link-child">
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
    <xsl:variable name="no-link1" select="boolean(number($hide-tc))"/>
    <xsl:variable name="no-link2" select="precondition/precondend/@fulfilled='false' and not($ShowFailedPreconditions)"/>
    <xsl:variable name="BackgroundClass">
      <xsl:choose>
        <xsl:when test="verdict/@result='pass'">TestcaseHeadingPositiveResult</xsl:when>
        <xsl:when test="verdict/@result='fail'">TestcaseHeadingNegativeResult</xsl:when>
        <xsl:when test="verdict/@result='na'">TestcaseHeadingDefaultResult</xsl:when>
        <xsl:when test="verdict/@result='error'">TestcaseHeadingErrorResult</xsl:when>
        <xsl:when test="verdict/@result='inconclusive'">TestcaseHeadingInconclusiveResult</xsl:when>
        <xsl:when test="verdict/@result='none'">TestcaseHeadingNoneResult</xsl:when>
      </xsl:choose>
    </xsl:variable>
    <tr>
      <td class="DefaultCell">
        <xsl:value-of select="$nr"/>
      </td>
      <td class='{$BackgroundClass}'>
        <xsl:if test="$no-link1 or $no-link2">
          <xsl:value-of select="./title"/>
        </xsl:if>
        <xsl:if test="not($no-link1 or $no-link2)">
          <a>
            <xsl:attribute name="href">
              <xsl:apply-templates select="." mode="href-file"/>
            </xsl:attribute>
            <xsl:value-of select="./title"/>
          </a>
        </xsl:if>
      </td>
    </tr>
  </xsl:template>
  <xsl:template match="preparation|completion" mode="link-child">
    <tr>
      <td class="DefaultCell"/>
      <td class="DefaultCell">
        <a>
          <xsl:attribute name="href">
            <xsl:apply-templates select="." mode="href-file"/>
          </xsl:attribute>
          <xsl:apply-templates select="." mode="name-of"/>
          <xsl:choose>
            <xsl:when test="../testmodule or ../testcycle">
              <xsl:apply-templates select="ancestor::testmodule" mode="name"/>
            </xsl:when>
            <xsl:otherwise>
              <xsl:apply-templates select=".." mode="name"/>
            </xsl:otherwise>
          </xsl:choose>
        </a>
      </td>
    </tr>
  </xsl:template>
  <xsl:template match="checkbegin|checkstartupinfo" mode="link-child">
    <tr>
      <td class="DefaultCell"/>
      <td  class="DefaultCell">
        <a>
          <xsl:attribute name="href">
            <xsl:apply-templates select="." mode="href-file"/>
          </xsl:attribute>
          <xsl:text>Startup of checks</xsl:text>
        </a>
      </td>
    </tr>
  </xsl:template>
  <xsl:template match="checkend|checkterminationinfo" mode="link-child">
    <tr>
      <td class="DefaultCell"/>
      <td class="DefaultCell">
        <a>
          <xsl:attribute name="href">
            <xsl:apply-templates select="." mode="href-file"/>
          </xsl:attribute>
          <xsl:text>Termination of checks</xsl:text>
        </a>
      </td>
    </tr>
  </xsl:template>

  <!-- Template: begin/end section, reused for testmodule, testunit, testsequence, testcase, preparation, completion -->
  <xsl:template name="beginend">
    <xsl:param name="what"/>
    <xsl:param name="nodeset"/>
    <table class="DefaultTable">
      <tr>
        <td style="padding-right: 0.5em;" class="CellNoColor"><xsl:value-of select="$what"/> begin: </td>
        <td style="padding-right: 0.5em;" class="CellNoColor"><xsl:value-of select="$nodeset/@starttime"/></td>
        <td class="CellNoColor">
          <xsl:text>(logging timestamp </xsl:text>
          <xsl:call-template name="showTimeStampImpl">
            <xsl:with-param name="timeStampValue" select="$nodeset/@timestamp"/>
          </xsl:call-template>
          <xsl:text>)</xsl:text>
        </td>
      </tr>
      <tr>
        <td style="padding-right: 0.5em;" class="CellNoColor"><xsl:value-of select="$what"/> end: </td>
        <td style="padding-right: 0.5em;" class="CellNoColor"><xsl:value-of select="$nodeset/@endtime"/></td>
        <td class="CellNoColor" nowrap="nowrap">
          <xsl:text>(logging timestamp </xsl:text>
          <xsl:call-template name="showTimeStampImpl">
            <xsl:with-param name="timeStampValue" select="$nodeset/@endtimestamp"/>
          </xsl:call-template>
          <xsl:text>)</xsl:text>
        </td>
      </tr>
    </table>
  </xsl:template>

  <xsl:template name="teststep-header">
    <tr>
      <th class="TableHeadingCell" width="1px">Timestamp</th>
      <th class="TableHeadingCell" width="1px">Test Step</th>
      <th class="TableHeadingCell" width="auto">Description</th>
      <th class="TableHeadingCell" width="1px">Result</th>
    </tr>
  </xsl:template>

  <xsl:template name="count-nodes-impl">
    <xsl:if test="$ShowSequenceAsGroup">
      <xsl:if test="$ShowTestListAsGroup">
        <xsl:call-template name="count-nodes-valid">
          <xsl:with-param name="nodeset" select="preceding-sibling::testgroup|preceding-sibling::testfixture|
            preceding-sibling::testsequence|preceding-sibling::testsequencelist|
            preceding-sibling::testcase|preceding-sibling::testcaselist|
            preceding-sibling::command/descendant::testcase"/>
        </xsl:call-template>
      </xsl:if>
      <xsl:if test="not($ShowTestListAsGroup)">
        <xsl:call-template name="count-nodes-valid">
          <xsl:with-param name="nodeset" select="preceding-sibling::testgroup|
            preceding-sibling::testfixture|preceding-sibling::testsequence|
            preceding-sibling::testsequencelist/descendant::testsequence|
            preceding-sibling::testcaselist/descendant::testcase|
            preceding-sibling::testcase|preceding-sibling::command/descendant::testcase"/>
        </xsl:call-template>
      </xsl:if>
    </xsl:if>
    <xsl:if test="not($ShowSequenceAsGroup)">
      <xsl:if test="$ShowTestListAsGroup">
        <xsl:call-template name="count-nodes-valid">
          <xsl:with-param name="nodeset" select="preceding-sibling::testgroup|
            preceding-sibling::testfixture|preceding-sibling::testcase|
            preceding-sibling::testsequencelist|preceding-sibling::testcaselist|
            (preceding-sibling::testsequence|preceding-sibling::command)/descendant::testcase[not(parent::testcaselist)]|
            preceding-sibling::testsequence/descendant::testcaselist"/>
        </xsl:call-template>
      </xsl:if>
      <xsl:if test="not($ShowTestListAsGroup)">
        <xsl:call-template name="count-nodes-valid">
          <xsl:with-param name="nodeset" select="preceding-sibling::testgroup|
            preceding-sibling::testfixture|preceding-sibling::testcase|
            (preceding-sibling::testsequencelist|preceding-sibling::testcaselist)/descendant::testcase|
            (preceding-sibling::testsequence|preceding-sibling::command)/descendant::testcase[not(parent::testcaselist)]|
            preceding-sibling::testsequence/descendant::testcase"/>
        </xsl:call-template>
      </xsl:if>
    </xsl:if>
  </xsl:template>
  <xsl:template name="count-nodes-valid">
    <xsl:param name="nodeset"/>
    <xsl:variable name="failed-nodes">
      <xsl:choose>
        <xsl:when test="$ShowFailedPreconditions">0</xsl:when>
        <xsl:otherwise>
          <xsl:value-of select="count($nodeset[precondition/precondend[@fulfilled='false']])"/>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:value-of select="count($nodeset) - $failed-nodes"/>
  </xsl:template>

  <xsl:template name="show-hide-tables">
    <xsl:param name="id"/>
    <table class="ScreenOnly">
      <tbody>
        <tr>
          <td>
            <a class="Undecorated">
              <xsl:attribute name="href">
                <xsl:text>javascript:showTable('</xsl:text>
                <xsl:value-of select="$id"/>
                <xsl:text>')</xsl:text>
              </xsl:attribute>
              <xsl:text>[expand test steps]</xsl:text>
            </a>
          </td>
          <td width="2px"/>
          <td>
            <a class="Undecorated">
              <xsl:attribute name="href">
                <xsl:text>javascript:hideTable('</xsl:text>
                <xsl:value-of select="$id"/>
                <xsl:text>')</xsl:text>
              </xsl:attribute>
              <xsl:text>[collapse test steps]</xsl:text>
            </a>
          </td>
        </tr>
      </tbody>
    </table>
  </xsl:template>
  <xsl:template name="show-hide-all">
    <xsl:param name="id"/>
    <xsl:param name="rowspan"/>
    <td class="LinkCell">
      <xsl:if test="$rowspan">
        <xsl:attribute name="rowspan">
          <xsl:value-of select="$rowspan"/>
        </xsl:attribute>
      </xsl:if>
      <a class="Undecorated">
        <xsl:attribute name="id">
          <xsl:value-of select="$LinkPrefix"/>
          <xsl:value-of select="$id"/>
        </xsl:attribute>
        <xsl:attribute name="href">
          <xsl:text>javascript:switchAll('</xsl:text>
          <xsl:value-of select="$id"/>
          <xsl:text>',document.all['</xsl:text>
          <xsl:value-of select="$LinkPrefix"/>
          <xsl:value-of select="$id"/>
          <xsl:text>'].text)</xsl:text>
        </xsl:attribute>
        <xsl:value-of select="$ExpandedText"/>
      </a>
    </td>
  </xsl:template>
  <xsl:template name="number-cycle">
    <xsl:choose>
      <xsl:when test="self::testcycle">
        <xsl:value-of select="count(preceding-sibling::testcycle)+1"/>
      </xsl:when>
      <xsl:when test="ancestor::testcycle">
        <xsl:value-of select="count(ancestor::testcycle[1]/preceding-sibling::testcycle)+1"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="''"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  <xsl:template name="aHref">
    <xsl:param name="externalID"/>
    <xsl:param name="externalFile"/>
    <xsl:param name="internalID"/>
    <xsl:param name="anchorText"/>
    <xsl:param name="onclick"/>
    <a>
      <xsl:attribute name="href">
        <xsl:if test="string-length($externalID) > 0">
          <xsl:value-of select="title"/>
          <xsl:value-of select="$externalFile"/>
        </xsl:if>
        <xsl:if test="string-length($internalID) > 0">
          <xsl:text>#</xsl:text>
          <xsl:value-of select="generate-id($internalID)"/>
        </xsl:if>
      </xsl:attribute>
      <xsl:if test="$onclick">
        <xsl:attribute name="onclick">
          <xsl:value-of select="$onclick"/>
        </xsl:attribute>
      </xsl:if>
      <xsl:value-of select="$anchorText"/>
    </a>
  </xsl:template>

  <xsl:template name="a-href-ext">
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

  <xsl:template match="testmodule" mode="name">
    <xsl:text>Test Module</xsl:text>
  </xsl:template>
  <xsl:template match="testcycle" mode="name">
    <xsl:text>Test Cycle</xsl:text>
  </xsl:template>
  <xsl:template match="testcycle[parent::testreport]" mode="name">
    <xsl:text>Cycle</xsl:text>
  </xsl:template>
  <xsl:template match="testgroup" mode="name">
    <xsl:text>Test Group</xsl:text>
  </xsl:template>
  <xsl:template match="testcase" mode="name">
    <xsl:text>Test Case</xsl:text>
  </xsl:template>
  <xsl:template match="preparation" mode="name">
    <xsl:text>Preparation</xsl:text>
  </xsl:template>
  <xsl:template match="completion" mode="name">
    <xsl:text>Completion</xsl:text>
  </xsl:template>
  <xsl:template match="preparation" mode="name-of">
    <xsl:text>Preparation of </xsl:text>
  </xsl:template>
  <xsl:template match="completion" mode="name-of">
    <xsl:text>Completion of </xsl:text>
  </xsl:template>

  <xsl:template name="hidetestcase">
    <xsl:param name="node-set" select="."/>
    <xsl:variable name="hide-tc">
      <xsl:apply-templates select="$node-set" mode="hidetestcase"/>
    </xsl:variable>
    <xsl:value-of select="$hide-tc"/>
  </xsl:template>
  <xsl:template match="testcase[verdict[@result='none']]" mode="hidetestcase">
    <xsl:if test="$HideNoneTestCases">
      <xsl:value-of select="'1'"/>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcase[verdict[@result='pass']]" mode="hidetestcase">
    <xsl:if test="$HidePassTestCases">
      <xsl:value-of select="'1'"/>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcase[verdict[@result='inconclusive']]" mode="hidetestcase">
    <xsl:if test="$HideInconTestCases">
      <xsl:value-of select="'1'"/>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcase[verdict[@result='fail']]" mode="hidetestcase">
    <xsl:if test="$HideFailTestCases">
      <xsl:value-of select="'1'"/>
    </xsl:if>
  </xsl:template>
  <xsl:template match="testcase[verdict[@result='error']]" mode="hidetestcase">
    <xsl:if test="$HideErrorTestCases">
      <xsl:value-of select="'1'"/>
    </xsl:if>
  </xsl:template>
  <xsl:template match="*" mode="hidetestcase"/>

</xsl:stylesheet>
<?xml version="1.0" encoding="ISO-8859-1" standalone="yes" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">  
    <!-- Color Definitions: The following section contains the definitions of  -->
    <!-- some colors that are used in the document. If you adjust these        -->
    <!-- definitions they will be used in the entire document. All colors are  -->
    <!-- RGB encoded with a single integer value from 0 to 255 for each color. -->
    
    <!-- Color that is used to emphasize positive test results -->
    <xsl:variable name="PositiveResultColor">rgb(25, 165, 0)</xsl:variable>
        
    <!-- Color that is used to emphasize negative test results in printouts -->
    <xsl:variable name="NegativeResultColor">rgb(240, 0, 0)</xsl:variable>

    <!-- Color that is used to emphasize negative test results in printouts -->
    <xsl:variable name="NoneResultColor">rgb(105, 105, 105)</xsl:variable>
    
    <!-- Color that is used to emphasize negative test results in printouts -->
    <xsl:variable name="InconclusiveResultColor">rgb(255, 165, 0)</xsl:variable>
    
    <!-- Color that is used to emphasize negative test results in printouts -->
    <xsl:variable name="ErrorResultColor">rgb(205, 0, 0)</xsl:variable>
     
    <!-- Color that is used to emphasize warnings -->
    <xsl:variable name="WarningColor">rgb(255, 255, 0)</xsl:variable>
    
    <!-- Color of the background of table cells -->
    <xsl:variable name="TableBackgroundColor">rgb(229, 229, 229)</xsl:variable>
    
    <!-- Color of table cells that should be emphasized, e.g. column headings -->
    <xsl:variable name="TableHeadingColor">rgb(179, 179, 179)</xsl:variable>
    
    <!-- Background color of the Report -->
    <xsl:variable name="BackgroundColor">rgb(255, 255, 255)</xsl:variable>
    
    <!-- Color of table cells that should be emphasized, e.g. column headings -->
    <xsl:variable name="HeadingBackgroundColor">rgb(220, 221, 222)</xsl:variable>
    
    <!-- Background color of the Navigation Frame -->
    <xsl:variable name="NavBackgroundColor">rgb(220, 221, 222)</xsl:variable>
   
    <!-- Color for table grids to use for printing (not visible in screen display) -->
    <xsl:variable name="PrintTableGridColor">rgb(150,150,150)</xsl:variable>

    <!-- Height of separator space above/below test pattern output inside test cases (including unit) -->
    <xsl:variable name="PatternSeparatorHeight">0.2em</xsl:variable>
    
	<xsl:variable name="TestCommentBackgroundColorTr6">rgb(211, 233, 246)</xsl:variable>
	
	<xsl:variable name="TestStepBackgroundColorTr6">rgb(222, 143, 96)</xsl:variable>
	
    <xsl:template name="cssDef">
      <!-- The section @media screen/print can be used if you want to use          -->
      <!-- different styles for displaying on screen and printing. Place styles in --> 
      <!-- the following section to use them for screen-rendering.                 -->
      @media screen
      {
        body
        {
          background-color: <xsl:copy-of select="$BackgroundColor" />;
          font-family:      arial, verdana, trebuchet, officina, sans-serif;
        }
      }
  
      <!-- This styles are used for printouts -->
      @media print
      {
        <!-- Use background color white -->
        body
        {
          background-color: rgb(255, 255, 255);
          font-family:      arial, verdana, trebuchet, officina, sans-serif;
        }
        
        <!-- don't underline links -->
        a
        {
          text-decoration: none;
        }
        
        <!-- Headers and Result tables are printed with borders because
             most browsers don't print background colors by default -->
        .HeadingTable, .SubHeadingTable, .GroupHeadingTable , .GroupEndTable
        {
          border-width: 2px;
          border-style: solid;
          border-color: <xsl:copy-of select="$PrintTableGridColor"/>;
        }
        
        .ResultBlockHeading
        {
          border-width: 1px;
          border-style: solid;
          border-color: <xsl:copy-of select="$PrintTableGridColor"/>;
        }
        
        table.ResultTable, table.OverviewTable, table.CheckStatisticsTable
        {
          border-collapse: collapse;
        }
        
        td.DefaultCell, td.DefineCell, td.NumberCell, td.NumberCellPositiveResult, td.NumberCellNegativeResult, 
        td.NumberCellErrorResult, td.NumberCellInconclusiveResult, td.NumberCellNoneResult, td.NumberCellNoColor,
        td.PositiveResultCell, td.NegativeResultCell, td.WarningCell, td.NoneResultCell, td.InconclusiveResultCell,
        td.ErrorResultCell, th.TableHeadingCell
        {
          border-width: 1px;
          border-style: solid;
          border-color: <xsl:copy-of select="$PrintTableGridColor"/>;
        }
        
        .PatternSeparator
        {
          <!-- remove border around separator cells -->
          border-style: none;
        }
        
        .PositiveResult
        {
          <!-- add "underlining" for printing without background colors -->
          border-bottom: 2px solid;
        }
        
        .NegativeResult
        {
          <!-- add "underlining" for printing without background colors -->
          border-bottom: 2px solid;
        }
        
        .NoneResult
        {
          <!-- add "underlining" for printing without background colors -->
          border-bottom: 2px solid;
        }
        
        .InconclusiveResult
        {
          <!-- add "underlining" for printing without background colors -->
          border-bottom: 2px solid;
        }
        
        .ErrorResult
        {
          <!-- add "underlining" for printing without background colors -->
          border-bottom: 2px solid;
        }

        
        .TestcaseHeadingDefaultResult
        {
          <!-- add "underlining" for printing without background colors -->
          border-bottom: 2px solid;
        }
        
        .TestcaseHeadingPositiveResult
        {
          <!-- add "underlining" for printing without background colors -->
          border-bottom: 2px solid;
        }
        
        .TestcaseHeadingNegativeResult
        {
          <!-- add "underlining" for printing without background colors -->
          border-bottom: 2px solid;
        }
        
        table.ScreenOnly, a.Undecorated, .LinkCell
        {
          display: none;
        }
      }
      
      a.Undecorated:hover 
      {
        color:red;
      }
      a.Undecorated
      { 
        text-decoration: none; 
      }
      
      .NavStyle
      {
        background-color: <xsl:value-of select="$NavBackgroundColor"/>;
      }
      
      td.LinkCell, td.UpCell
      {
        <!--background-color:   <xsl:value-of select="$NavBackgroundColor"/>;-->
        width:              1px;
        white-space:        nowrap;
      }

      <!-- Table styles -->
      table
      {
        margin-bottom:    10px;
        vertical-align:   top; 
        border:           0;
        border-spacing:   1px;
        padding:          2px;
      }
      table.ScreenOnly
      {
        vertical-align: top; 
        margin-bottom:  10px;
      }
      .NoMarginBottom
      {
        margin-bottom:    0px;
      }
      .HeadingTable
      {
        width:            100%;
        text-align:       center;
        margin-top:       15px;
        margin-bottom:    30px;
        margin-left:      auto;
        margin-right:     auto;
        background-color: <xsl:copy-of select="$HeadingBackgroundColor" />;
      }
      
      .SubHeadingTable
      {
        width:            100%;
        text-align:       center;
        margin-top:       15px;
        margin-bottom:    25px;
        background-color: <xsl:copy-of select="$HeadingBackgroundColor" />;
      }
      
      .GroupHeadingTable, .GroupEndTable
      {
        width:            100%;
        text-align:       center;
        margin-top:       15px;
        padding-right:    <xsl:copy-of select="$IndentDepth"/>px;
        background-color: <xsl:copy-of select="$HeadingBackgroundColor" />;
      }
      
      .DefaultTable
      {
        padding:        0px;
        border-spacing: 0px;
      }
      
      .CheckStatisticsTable
      {
        margin-bottom: 8px;
        padding-right:  <xsl:copy-of select="$IndentDepth"/>px;
      }
  
      .OverviewTable
      {
        text-align:     left;
      }
      
      .OverviewResultTable
      {
        width:          100%;
        margin-bottom:  0px;
        border-spacing: 0px;
        padding:        0px;
        text-align:     center;
      }
      
      .ResultTable
      {
        width:          100%;
        text-align:     left;
        padding-right:  <xsl:copy-of select="$IndentDepth"/>px;
      }
      
      .ResultTableInner
      {
        width:          100%;
        text-align:     left;
        padding-right:  0px;
      }
  
      table.ResultTable td, table.ChildLinkTable td
      {
        vertical-align: top;
      }
      .ChildLinkTable
      {
        width:          1px;
        text-align:     left;
      }
      .InfoTable
      {
        text-align:     left;
        padding-right:  0px;
        margin-bottom:  0px;
        border-spacing: 0px;
      }
      .InfoTableExpand
      {
        width:          100%;
        text-align:     left;
        padding-right:  0px;
        margin-bottom:  0px;
        border-spacing: 1px;
      }
      .OverallResultTable
      {
        width:         50%;
        text-align:    center;
        margin-bottom: 20px;
        margin-left:   auto;
        margin-right:  auto;
        font-weight:   bold;
      }
      
      .TableHeadingCell
      {
        background-color: <xsl:copy-of select="$TableHeadingColor" />;
        font-family:      arial, verdana, trebuchet, officina, sans-serif;
        font-weight:      bold;
        text-align:       left;
      }
	  
      .CellNoColor
      {
        text-align:     left;
        vertical-align: top;
      }   
      
      .DefineCell
      {
        background-color: <xsl:copy-of select="$TableHeadingColor" />;
        text-align:       left;
      }
      
      .DefaultCell
      {
        background-color: <xsl:copy-of select="$TableBackgroundColor" />;
        text-align:       left;
      }
	  
	  .DefaultCellTestStep
      {
		background-color: <xsl:copy-of select="$TableBackgroundColor" />;
        text-align:       left;
		font-weight:      bold;
      }
	  
	   .DefaultCellTestStepCellBlueUnderline
      {
		background-color: <xsl:copy-of select="$TableBackgroundColor" />;
        text-align:       center;
		font-weight:      bold;
		font-style: 	  italic;
		text-decoration:  underline;
		color: 			  rgb(4,45,229);
      }
      
      .DefaultCellBold
      {
		background-color: <xsl:copy-of select="$TestCommentBackgroundColorTr6" />;
        font-weight:      normal;
		text-decoration:  underline;
		color: 			  rgb(4,45,229);
		font-style: 	  italic;
      }
        
      .NumberCell
      {
        background-color: <xsl:copy-of select="$TableBackgroundColor" />;
        text-align:       center;
        min-width:        50px;
      }
      
      .NumberCellNegativeResult
      {
        background-color: <xsl:copy-of select="$NegativeResultColor" />;
        text-align:       center;
        min-width:        50px;
      }
      
      .NumberCellPositiveResult
      {
        background-color: <xsl:copy-of select="$PositiveResultColor" />;
        text-align:       center;
        min-width:        50px;
      }
      
      .NumberCellNoneResult
      {
        background-color: <xsl:copy-of select="$NoneResultColor" />;
        text-align:       center;
        text-align:       center;
        min-width:        50px;
      }
      
      .NumberCellInconclusiveResult
      {
        background-color: <xsl:copy-of select="$InconclusiveResultColor" />;
        text-align:       center;
        min-width:        50px;
      }
      
      .NumberCellErrorResult
      {
        background-color: <xsl:copy-of select="$ErrorResultColor" />;
        text-align:       center;
        min-width:        50px;
      }
      
      .NumberCellNoColor
      {        
        text-align: center;
      }
      
      .PositiveResultCell
      {
        background-color: <xsl:copy-of select="$PositiveResultColor" />;
      }
    
      .NegativeResultCell
      {
        background-color: <xsl:copy-of select="$NegativeResultColor" />;
      }
      
      .NoneResultCell
      {
        background-color: <xsl:copy-of select="$NoneResultColor" />;
      }
      
      .InconclusiveResultCell
      {
        background-color: <xsl:copy-of select="$InconclusiveResultColor" />;
      }
      
      .ErrorResultCell
      {
        background-color: <xsl:copy-of select="$ErrorResultColor" />;
        white-space:        nowrap;
      }

      .WarningCell
      {
        background-color: <xsl:copy-of select="$WarningColor" />;
      }

      .TestcaseHeadingDefaultResult
      {
        background-color: <xsl:copy-of select="$TableHeadingColor" />;
      }
      .TestcaseHeadingPositiveResult
      {
        background-color: <xsl:copy-of select="$PositiveResultColor" />;
      }      
      .TestcaseHeadingNegativeResult
      {
        background-color: <xsl:copy-of select="$NegativeResultColor" />;
      }      
      .TestcaseHeadingNoneResult
      {
        background-color: <xsl:copy-of select="$NoneResultColor" />;
      }
      .TestcaseHeadingInconclusiveResult
      {
        background-color: <xsl:copy-of select="$InconclusiveResultColor" />;
      }
      .TestcaseHeadingErrorResult
      {
        background-color: <xsl:copy-of select="$ErrorResultColor" />;
      }
      
      .PatternSeparator
      {
        height: <xsl:copy-of select="$PatternSeparatorHeight"/>;
      }
      
      .NegativeResult
      {
        background-color: <xsl:copy-of select="$NegativeResultColor" />;
        text-align:       center;
        font-weight:      bold;
      }
      .PositiveResult
      {
        background-color: <xsl:copy-of select="$PositiveResultColor" />;
        text-align:       center;
        font-weight:      bold;
      }
      .NoneResult
      {
        background-color: <xsl:copy-of select="$NoneResultColor" />;
        text-align:       center;
        font-weight:      bold;
      }
      .InconclusiveResult
      {
        background-color: <xsl:copy-of select="$InconclusiveResultColor" />;
        text-align:       center;
        font-weight:      bold;
      }
      .ErrorResult
      {
        background-color: <xsl:copy-of select="$ErrorResultColor" />;
        text-align:       center;
        font-weight:      bold;
      }
      
      
      <!-- Heading styles -->
      .Heading1
      {
        font-family: arial, sans-serif;
        font-weight: bold;
        font-size:   26px;
      }
      
      .Heading2
      {
        font-family: arial, sans-serif;
        font-weight: bold;
        font-size:   20px;
      }
      
      .Heading3
      {
        font-family:   arial, sans-serif;
        font-weight:   bold;
        font-size:     18px;
        margin-bottom: 20px;
        margin-top:    20px;
      }
      
      .Heading4
      {
        font-family:   arial, sans-serif;
        font-weight:   bold;
        font-size:     16px;
        margin-top:    10px;
        margin-bottom: 10px;
      }
      
      <!-- Margins for all images -->
      img
      {
        Margin-bottom: 10px;
        Margin-right:  10px;
      }
      
      <!-- Bottom margin for all paragraphs-->
      p
      {
        Margin-bottom: 20px;
      }
      
      <!-- Styles with Background Colors for different results -->
      .DefaultTableBackground
      {
        background-color: <xsl:copy-of select="$TableBackgroundColor" />;
        border-spacing:   0px;
        padding:          0px;
      }
      
      .NegativeResultBackground
      {
        background-color: <xsl:copy-of select="$NegativeResultColor" />;
        border-spacing:   0px;
        padding:          0px;
      }
      
      .PositiveResultBackground
      {
        background-color: <xsl:copy-of select="$PositiveResultColor" />;
        border-spacing:   0px;
        padding:          0px;
      }
      
      .WarningResultBackground
      {
        background-color: <xsl:copy-of select="$WarningColor" />;
        border-spacing:   0px;
        padding:          0px;
      }
      
      .NoneResultBackground
      {
        background-color: <xsl:copy-of select="$NoneResultColor" />;
        border-spacing:   0px;
        padding:          0px;
      }
      
      .InconclusiveResultBackground
      {
        background-color: <xsl:copy-of select="$InconclusiveResultColor" />;
        border-spacing:   0px;
        padding:          0px;
      }
      
      .ErrorResultBackground
      {
        background-color: <xsl:copy-of select="$ErrorResultColor" />;
        border-spacing:   0px;
        padding:          0px;
      }
      
      .TestGroupHeadingBackground
      {
        background-color: <xsl:copy-of select="$TableHeadingColor" />;
      }
    
      <!-- Style for indentation -->
      .Indentation
      {
        margin-left:  <xsl:copy-of select="$IndentDepth" />px;
      }
    </xsl:template>
    <xsl:template name="cssStyleDef">
      <style type="text/css">
          <xsl:call-template name="cssDef"/>
      </style>
    </xsl:template>
</xsl:stylesheet>
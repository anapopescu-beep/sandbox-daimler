<?xml version="1.0" encoding="ISO-8859-1" standalone="yes" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  
  <!-- displays the number for test elements -->  
  <xsl:template name="show-number-impl">
    <xsl:number level="multiple" count="testgroup|testcase" />
  </xsl:template>
  
  <xsl:template name="make-number-impl">
    <xsl:call-template name="show-number-impl"/>
  </xsl:template>
  
  <xsl:template match="engineer" mode="title">
    <div class="Heading4"><xsl:text>Test Engineer</xsl:text></div>
  </xsl:template>
   
</xsl:stylesheet>
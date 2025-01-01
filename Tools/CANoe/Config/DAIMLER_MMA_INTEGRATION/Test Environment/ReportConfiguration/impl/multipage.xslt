<?xml version="1.0" encoding="ISO-8859-1" standalone="yes" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">  
  
  <xsl:template name="showTimeStampImpl">
    <xsl:param name="timeStampValue"/>
    <xsl:value-of select="$timeStampValue"/>
  </xsl:template>
  
</xsl:stylesheet>

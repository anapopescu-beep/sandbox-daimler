<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:variable name="LinkPrefix" select="'lnk_'"/>
  <xsl:variable name="TablePrefix" select="'tbl_'"/>
  <xsl:variable name="Table2Prefix" select="'tbl_t'"/>
  <xsl:variable name="DivPrefix" select="'div_'"/>
  <xsl:variable name="ExpandedText" select="'[−]'"/>
  <xsl:variable name="CollapsedText" select="'[+]'"/>
  <xsl:template name="expand-script">
    <script type="text/javascript">
      var EXPANDED = '<xsl:value-of select="$ExpandedText"/>';
      var COLLAPSED = '<xsl:value-of select="$CollapsedText"/>';
      var VISIBLE = 'Visible';
      var HIDDEN = 'Hidden';
      var NONE = 'none';
      var BLOCK = '';
      function getDivId(id) { return '<xsl:value-of select="$DivPrefix"/>' + id; }
      function getLinkId(id) { return '<xsl:value-of select="$LinkPrefix"/>' + id; }
      function getTableId(id) { return '<xsl:value-of select="$TablePrefix"/>' + id; }
      function getTbl2Id(id) { return '<xsl:value-of select="$Table2Prefix"/>' + id; }
      
      <![CDATA[
      function switchText(oldText) { return oldText == COLLAPSED ? EXPANDED : COLLAPSED ; }
      function getStyleFromText(linkText) { return linkText == COLLAPSED ? HIDDEN : VISIBLE; }
      
      function getElements(tagName, elementId)
      {
        this.elements = [];
        var index = 0;
        var elm = document.getElementsByTagName(tagName);
        var len = elm.length;
        for (var i = 0; i < len; i++) 
        {
          var id = elm[i].id;
          if (id && id.indexOf(elementId) == 0)
          {
            this.elements[index] = elm[i];
            index++;
          }
        }
        return this.elements;
      }
      function matchElements(tagName, matchId)
      {
        this.elements = [];
        var index = 0;
        var elm = document.getElementsByTagName(tagName);
        for (var i = 0; i < elm.length; i++) 
        {
          var id = elm[i].id;
          var tc = id.replace(/s[0-9]+\./, "");
          if (tc && tc == matchId)
          {
            this.elements[index] = elm[i];
            index++;
          }
        }
        return this.elements;  
      }
      function onoff(elm, style)
      {
        if(elm.style.display == NONE)
        {
          if(style == null || style == VISIBLE)
            elm.style.display = BLOCK;
        }
        else
        {
          if(style == null || style == HIDDEN)
            elm.style.display = NONE;
        }
      }
      function switchTagStyle(tag, id, style)
      {
        var divs = getElements(tag, id);
        for(var i = 0; i < divs.length; i++)
          onoff(divs[i], style);
      }
      function switchRowStyle(tbl, style)
      {
        var rows = tbl.rows.length;
        for(var rowIndex=0; rowIndex < rows; rowIndex++)
        {
          var row = tbl.rows[rowIndex];
          if (row.id != "on")
            onoff(row, style);
        }
      }
      function switchTableRowStyle(tableId, style)
      {
        var tables = getElements('table', tableId);
        for(var i = 0; i < tables.length; i++)
          switchRowStyle(tables[i], style);
      }
      function switchLinkText(linkId, newText)
      {
        var link = getElements('a', linkId);
        var len = link.length;
        for(var i = 0; i < len; i++)
        {
          var lnk = link[i];
          if(newText == null)
          {
            var oldText = lnk.text;
            newText = switchText(oldText)
          }
          lnk.text = newText;
        }
      }
      function switchTag(tag, id, text)
      {
        var style = getStyleFromText(text);
        switchTagStyle(tag, id, style);
      }
      function switchTable(id)
      {
        switchLinkText(getTableId(id));
        switchTableRowStyle(getTableId(id));
      }
      function switchDiv(id, linkText)
      {
        var text = switchText(linkText);
        switchLinkText(getLinkId(id), text);
        switchTag('div', getDivId(id), text);
      }      
      function switchAll(id, linkText)
      {
        var text = switchText(linkText);
        switchLinkText(getLinkId(id), text);
        switchTag('div', getDivId(id), text);
        var style = getStyleFromText(text);
        switchTableRowStyle(getTbl2Id(id), style);
      }
      function showTable(id)
      {
        var tableId = getTableId(id);
        switchLinkText(tableId, EXPANDED);
        switchTableRowStyle(tableId, VISIBLE);
      }
      function hideTable(id)
      {
        var tableId = getTableId(id);
        switchTableRowStyle(tableId, HIDDEN);
        switchLinkText(tableId, COLLAPSED);
      }
      function showDiv(id)
      {
        switchLinkText(getLinkId(id), EXPANDED);
        switchTag('div', getDivId(id), EXPANDED);
      }
      function showTC(id)
      {
        var divId = getDivId(id);
        var elms = matchElements('div', divId); 
        if(elms != null && elms.length > 0)
        {
          id = elms[0].id.replace(getDivId(''), '');
          showDiv(id);
        }
      }
      ]]>
    </script>
  </xsl:template>
</xsl:stylesheet>

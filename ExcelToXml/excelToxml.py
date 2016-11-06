#coding='utf-8'
import sys
reload(sys) 
sys.setdefaultencoding('utf-8') 
import xlrd
import types 
import math
import xml.dom.minidom

class DataTable():
    """docstring for tableDes"""
    def __init__(self, xmlNode):
        self.MapItem = {}
        self.MapType = {}
        self.Name = xmlNode.getAttribute('name')
        self.ExcelFile = xmlNode.getAttribute('file')
        self.ExcelSheet = xmlNode.getAttribute('sheet')
        self.BeginRow = int(xmlNode.getAttribute('begin_row')) - 1
        if self.BeginRow <= 0:
            print("begin_row must big than 1")
            print("Error in table %s"%(self.Name))


        '''self.BeginCol = int(xmlNode.getAttribute('begin_col'))'''
        for item in xmlNode.getElementsByTagName('col'):
            self.MapType[item.getAttribute('name')] = item.getAttribute('type')

    def ParseExcel(self, excelPath, xmlOutPath):
        xmlFile = open(xmlOutPath+self.Name + ".xml", 'wb')
        xmlFile.write(u'<?xml version="1.0" encoding="utf-8" ?>\n')
        xmlFile.write(u'<root>\n')
        excelfile = excelPath + self.ExcelFile
        table = xlrd.open_workbook(excelfile)
        sheet = table.sheet_by_name(self.ExcelSheet)
        mapIndexName = {}
        for i in range(0, sheet.ncols):
            cellValue = sheet.row(self.BeginRow -1)[i].value
            if cellValue != u'':
                mapIndexName[i] = cellValue
                
        for row in range(self.BeginRow, sheet.nrows):
            strItem = u'\t<item '
            IsNull = True
            for col in range(0, sheet.ncols):
                cellValue = sheet.cell(row, col).value
                if cellValue != u'' and mapIndexName.has_key(col):
                    cellValue = self.GetString(cellValue, mapIndexName[col])
                    strValue = u'%s="%s" ' % (mapIndexName[col], str(cellValue).encode('utf8'))
                    strItem += strValue
                    IsNull = False
            strItem += u'/>\n'
            if IsNull == False:
                xmlFile.write(strItem)
        xmlFile.write(u'</root>\n')
    
    def GetString( self,value, name):
        if self.MapType.has_key(name):
            valueType = self.MapType[name]
            if valueType == u'int':
                value = int(value)
            elif valueType == u'percent':
                value = int(value*100)
            elif valueType == u'float':
                value = float(value)
        elif type(value) is types.FloatType:
            ret = math.modf(value)
            if ret[0] == 0.0:
                value = int(value) 
        return value

class TableGen:
    
    def __init__(self, xmlfileName, excelPath, outPath):
        dom = xml.dom.minidom.parse(xmlfileName)
        root = dom.documentElement
        for table in root.getElementsByTagName("table"):
            dataTable = DataTable(table)
            dataTable.ParseExcel(excelPath, outPath)

import sys


"""test = TableGen('table.xml')
test.Parse(".", ".")"""

if len(sys.argv) == 4:
    test = TableGen(sys.argv[1], sys.argv[2], sys.argv[3])
    """test.Parse(sys.argv[2], sys.argv[3])"""
    print "gen success!"
else:
    print u"Need to input the correct parameters : (xml file Name) (excel file path) (xml out path)"
    print u"like: table.xml ./ ./"

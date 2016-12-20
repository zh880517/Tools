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
    def __init__(self, outFile, sheetName, beginRow):
        self.MapItem = {}
        self.MapType = {}
        self.Name = outFile
        self.ExcelSheet = sheetName
        self.BeginRow = int(beginRow) - 1
        if self.BeginRow <= 1:
            print("begin_row must big than 2")
            print("Error in table %s"%(self.Name))


        '''self.BeginCol = int(xmlNode.getAttribute('begin_col'))
        for item in xmlNode.getElementsByTagName('col'):
            self.MapType[item.getAttribute('name')] = item.getAttribute('type')
        '''

    def ParseExcel(self):
        xmlFile = open(self.Name + ".xml", 'wb')
        xmlFile.write(u'<?xml version="1.0" encoding="utf-8" ?>\n')
        xmlFile.write(u'<root>\n')
        sheet = self.ExcelSheet
        mapIndexName = {}
        for i in range(0, sheet.ncols):
            cellValue = sheet.row(self.BeginRow -1)[i].value
            if cellValue != u'':
                mapIndexName[i] = cellValue
                valueType = sheet.row(self.BeginRow -2)[i].value
                if valueType != u'':
                    self.MapType[i] = valueType
                
        for row in range(self.BeginRow, sheet.nrows):
            strItem = u'\t<item '
            IsNull = True
            for col in range(0, sheet.ncols):
                cellValue = sheet.cell(row, col).value
                if cellValue != u'' and mapIndexName.has_key(col):
                    cellValue = self.GetString(cellValue, col)
                    strValue = u'%s="%s" ' % (mapIndexName[col], str(cellValue).encode('utf8'))
                    strItem += strValue
                    IsNull = False
            strItem += u'/>\n'
            if IsNull == False:
                xmlFile.write(strItem)
        xmlFile.write(u'</root>\n')
    
    def GetString( self,value, col):
        if self.MapType.has_key(col):
            valueType = self.MapType[col]
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
    
    def __init__(self, excelFile, outPath):
        table = xlrd.open_workbook(excelFile)
        print 'export excel file ---', excelFile
        for sheet in table.sheets():
            listStr = sheet.name.split('|')
            print '   |-- sheet --- ' , sheet.name 
            if len(listStr) == 3:
                dataTable = DataTable( outPath + listStr[1], sheet, listStr[2])
                dataTable.ParseExcel()

import sys


"""test = TableGen('table.xml')
test.Parse(".", ".")"""

if len(sys.argv) == 3:
    TableGen(sys.argv[1], sys.argv[2])
    print "gen success!"
elif len(sys.argv) == 2:
    TableGen(sys.argv[1], u'./')
    print "gen success!"
else:
    print u"Need to input the correct parameters :(excel file) (xml out path)"
    print u"like: table.xlsx ./"
    print u' or  (excel file) like table.xlsx'

'ФОРМИРОВАНИЕ МЕСЯЧНОГО ОТЧЕТА

'ВАЖНО: Список датчиков необходимо составлять в той последовательности в какой они идут в файлах ежедневных отчетов
'это сделано ускорения поиска, проход по файлу в поисках нужных строх осуществляется только 1 раз

'Список датчиков включенных в месячный отчет
dataSensors = array("085-FIT001","086-FIT001","087-FIT001","089-FT001","089-FT002","090-FT001","090-FT002","090-FT003","090-FT004","090-FT005","090-FT006","104-FIA001","104-FIA002","104-FIA003","104-FIA004","104-FIA005","104-FIA006","104-FIA007","105-FIT001","105-FIT002")
					
totalRows = UBound(dataSensors)
Dim outputData()
Redim outputData(totalRows,30) 'строки/столбцы

'Формирование имени файла
Dim month, year, numOfFiles, percLine, err 'месяц/год/число файлов/процентная шкала/ошибка

month = 7 'Месяц, затем получать из WinCC
year = 2019 'Год

daysOfMonth = Day(DateSerial(year, month + 1, 0)) 'Дней в месяце
'Проверка что в директории есть необходимое количество файлов 
folder = "C:\Reports\" + CStr(month) + "\"

Set FSO = CreateObject("Scripting.FileSystemObject")
Set objFolder = FSO.GetFolder("C:\Reports\7\")
Set colFiles = objFolder.Files

'посчитаем файлы
For Each objFile in colFiles
    numOfFiles = numOfFiles + 1
Next

'Количество файлов в папке равно числу дней месяца, можно сформировать отчет
if numOfFiles = daysOfMonth then 
	Set oExcel = CreateObject("Excel.Application")
	
	For i = 0 To daysOfMonth - 1 '#СТОЛБЦЫ - дни месяца
		percLine = percLine + (100 / daysOfMonth) 'процентная шкала
		MsgBox percLine
		file = folder + "Mode_Sheet_" + Cstr(i + 1) + "-" + Cstr(month) + "-2019"    'сформировали имя файла
		Set oBook = oExcel.Workbooks.Open (file)' открыли

'Данные для внутреннего цикла #СТРОКИ - датчики
		rowsNum = 3  'для того чтобы пробежать по дневному отчету и не зависить от его длины
		sensName = 0 'Данные которые надо найти и считать для месячного отчета
		stopScan = 0

'Ищем датчики последовательно, поиск оканчиваем в первой попвшейся пустой строке		
		Do While sensName < (UBound(dataSensors) + 1) and stopScan = 0
			if oBook.Sheets(1).Cells(rowsNum,2).Value = dataSensors(sensName) then
				outputData(sensName,i) = oBook.Sheets(1).Cells(rowsNum,4).Value
				sensName = sensName + 1
				rowsNum = rowsNum + 1
'Файл просмотрен, возможно не все искомые элементы найдены
			elseif oBook.Sheets(1).Cells(rowsNum,2).Value = "" then 
				stopScan = 1
			else
				rowsNum = rowsNum + 1
			end if
		Loop		
		oExcel.ActiveWorkbook.Close 'закрыли файл	
	Next 

'Запись полученных данных в месячный отчет:
	outputFile = "C:\Reports\Blank\Mode_Sheet_Month.xlsx"
	Set reportBook = oExcel.Workbooks.Open(outputFile)

	reportBook.Sheets(1).Range("H4").Resize(totalRows + 1, daysOfMonth) = outputData
	reportBook.SaveAs "C:\Reports\Mode_Sheet_" + Cstr(month) + "-" + Cstr(year) + "_month.xlsx"
	
	percLine = 100
	MsgBox percLine
	
	oExcel.ActiveWorkbook.Close 'закрыли файл
	oExcel.Quit ' вышли
	
else
err = 1	'Ошибка выполнения

end if
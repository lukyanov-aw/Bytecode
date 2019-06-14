Транслятор ассемблероподобного языка в самодельный байткод и виртуальная машина для его выполнения.

Проект 2011 года, писался для конкурса школьников IT-2011, проводимого МФТИ. Был признан победителем.
https://mipt.ru/drec/abitur/zaolimpArchive/it2011/results.php
Код грязноват и плохо задокументирован, а также использует сомнительные практики вроде владеющих нативных указателей.
Основной целью при написании было достижение максимальной скорости - того, чего не хватало предыдущему проекту.
Развитие не планируется.

Состоит из:
1. транслятора ассемблероподобного языка в байт-код, litrs32.exe, проект LITrs;
2. виртуальной машины для выполнения полученного байт-кода, li32.exe, проект LIEng;
3. программы для ручной генерации файла с байт-кодом, предшественника litrs, проект dbgCodeGen.

В папке DOC есть примеры кода, которые могут быть скомпилированы и запущены на виртуальной машине:
1. Решение олимпиадной задачи, взятой из другой секции того же конкурса.
   Уже не помню, к сожалению, что в точности она делает и желания разбираться в ней нет.
   По исходнику видно что она вводит два числа (через пробел) и выдаёт соответствующий этой комбинации символ.
2. Пример, вызывающий функцию MessageBox и обрабатывающий выбор пользователя.
3. Простейшее оконное приложение Win32, выводящее надпись "Hello World" по центру окна и обрабатывающее вызов callback'а.

В самом интерпретаторе нет никакой поддержки работы с КОНКРЕТНЫМИ Win32API-функциями, вызываемыми в примерах,
есть только общий механизм вызова внешних функций и регистрации функций обратного вызова.

!!! ВАЖНО !!!
Поскольку напрямую передать управление на байт-код невозможно, а интерпретатор не может знать заранее обо всех
callback'а кода который ему предстоит выполнять, то функции обратного вызова создаются динамически в хипе
(примитивная самомодификация) и на них впоследсивии передаётся управление.
Поэтому требуется отключить DEP (защиту от выполнения данных) в Windows перед запуском интерпретатора.
Данный момент решён в следующем похожем проекте (fuura), но здесь для запуска придётся отключать DEP.

Скомпилированная версия с примерами ассемблероподобного кода там: https://drive.google.com/file/d/1DLOMOJO8--QRCFce5DJfgiYPDZrxBTGY/view
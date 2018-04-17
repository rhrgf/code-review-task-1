alpha version, 20180410

+ Using lambda expression feature, please compile it in jdk v1.8 or higher version.
+ Encapsuled the file operator class FileReaderUtils with "Strategy pattern", all file handler implement ITextFileHandler interface could become a strategy and set to FileReaderUtils.
+ The target class TextFileWordCount is a concreate strategy implement the interface ITextFileHandler. It uses a Map with key(String) and value(Integer) to memorize the word freq.
+ IResultShow is the interface to Show the final result. In this case, we implement this interface with class CResultShowInConsole, which re-ordered the result by desc-order and showed it in console.
+ **feedback from instructor:** 

  + May exists over-designed problems in this project.
+ **feedback during the code review process with group members**:
  + There is no unit-tests in this project.
  + the relationships between entities and classes are too complex to understand.
  + exception handleing problems: catch the exceptions without handlering them.
  + coding style is not always uniform in all files(such as Class name with C/I stands for Class/Interface in some files).


beta version, 20180417

+ Refactored the file operator class FileHandler with "Template Method", which has an abstract method called Handle and receives a parameter whose type is BufferedReader.
+ LineCountFileHandler derived from FileHandler, which implements the Handle method and can be used to count the word freq.
+ MainApp get the result from LineCountFileHandler, re-order it in desc-order and show it in console.
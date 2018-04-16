package com.philosjay.fileReader;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;

public class FileReader {
    private FileInputStream fin = null;
    private String encoding = "UTF-8";
    private String content = null;
    byte[] filecontent = null;

    public void loadFile(String fileName){
        try {

            File file = new File(fileName);
            Long filelength = file.length();
            filecontent = new byte[filelength.intValue()];

            fin = new FileInputStream(fileName);

            fin.read(filecontent);
            fin.close();

            content = new String(filecontent,encoding);

        } catch (FileNotFoundException e) {
            System.out.println("file not found.");
            return;
        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    public List<String> getElements(){

        return ElementIdentifier.getElements(content);
    }

    public List<String> getWords(){

        return ElementIdentifier.getWords(content);
    }
}

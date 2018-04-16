package com.philosjay.test;

import com.philosjay.fileReader.Element;
import com.philosjay.fileReader.FileReader;
import org.junit.Test;

import java.util.List;

public class TestDemo {
    @Test
    public void getElements(){
        FileReader reader = new FileReader();
        reader.loadFile("test3.txt");

        List<String> elements = reader.getElements();

        for (String element:
             elements) {
            System.out.println(element);
        }


    }

}

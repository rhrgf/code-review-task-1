package com.philosjay.app;

import com.philosjay.elementHandler.WordCounter;
import com.philosjay.fileReader.FileReader;

import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class Application {
    static public void main(String[] args){

        FileReader fileReader = new FileReader();
        fileReader.loadFile("test.txt");

        //获取所有单词
        List<String> words = fileReader.getElements();

        for (int i=0;i<words.size();i++){
            System.out.println(words.get(i));
        }

//        WordCounter wordCounter = new WordCounter();
//
//        //获取统计结果
//        List<Map.Entry<String,Integer>> result = wordCounter.countWord(words);
//
//        for (Map.Entry<String,Integer> word:
//             result) {
//            System.out.println(word.getKey() + "   " + word.getValue());
//        }


    }
}

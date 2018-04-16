package com.philosjay.fileReader;

import com.philosjay.fileReader.elementLocator.ElementLocator;
import com.philosjay.fileReader.elementLocator.ElementLocatorFactory;
import com.philosjay.fileReader.elementLocator.WordLocator;

import java.util.*;

public class ElementIdentifier {

    static public List<String> getElements(String text){

        List<String> elements = new ArrayList<>();


        //先分别识别并定位单词、标点、空格等元素，分别储存在各自的List<Element>中
        List<List<Element>> segList = new ArrayList<>();
        segList.add(ElementLocatorFactory.get("WordLocator").locate(text));
        segList.add(ElementLocatorFactory.get("PunctuationLocator").locate(text));
        segList.add(ElementLocatorFactory.get("NumberLocator").locate(text));
        segList.add(ElementLocatorFactory.get("BlankLocator").locate(text));
        
        //使用 归并排序算法 拼接各种元素，以获得顺序装有全文单词、标点、空格等元素的List<Element>，供后续处理
        long min = text.length();
        int segIndex = 0;

        // 获取非空元素List数量
        int countDown = segList.size();
        for (int i=0;i<segList.size();i++){
            if (segList.get(i).size()==0) countDown--;
        }
        //开始排序
        while (countDown>0){
            for (int i=0; i< segList.size(); i++){


                if (segList.get(i).size()==0){
                    if (i == segList.size() - 1){

                        elements.add(segList.get(segIndex).get(0).content);
                        segList.get(segIndex).remove(0);
                        if (segList.get(segIndex).size()==0){
                            countDown--;
                        }

                        segIndex = 0;
                        min = text.length();
                    }
                    continue;   // list为空进入下一层遍历
                }

                long indexInText = segList.get(i).get(0).indexInText;
                if (indexInText < min){
                    min = indexInText;
                    segIndex = i;
                }

                if (i == segList.size() - 1){
                    // 选出最靠前的元素
                    elements.add(segList.get(segIndex).get(0).content);
                    segList.get(segIndex).remove(0);
                    if (segList.get(segIndex).size()==0){
                        countDown--;
                    }

                    segIndex = 0;
                    min = text.length();
                }

            }
        }
        return elements;

    }


    static public List<String>  getWords(String text){
        //从装有单词的List<Element>中提取单词

        List<String> wordList = new ArrayList<>();

        List<Element> words = ElementLocatorFactory.get("WordLocator").locate(text);
        for (Element word:
             words) {
         wordList.add(word.content);
        }

        return wordList;
    }


}

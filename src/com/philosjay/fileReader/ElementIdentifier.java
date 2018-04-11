package com.philosjay.fileReader;

import java.util.*;

public class ElementIdentifier {

    static public List<String> getElements(String text){

        List<String> elements = new ArrayList<>();


        List<List<Element>> segList = new ArrayList<>();
        segList.add(locateWords(text));
        segList.add(locatePunctuation(text));
        segList.add(locateBlanks(text));

        long min = text.length();
        int segIndex = 0;

        int countDown = segList.size();
        while (countDown>0){
            for (int i=0; i< segList.size(); i++){


                if (segList.get(i).size()==0){
                    if (i == segList.size() - 1){
                        elements.add(segList.get(segIndex).get(0).content);
                        segList.get(segIndex).remove(0);
                        if (segList.get(segIndex).size()==0){
                            countDown--;
                        }

                        min = text.length();
                    }
                    continue;
                }

                long indexInText = segList.get(i).get(0).indexInText;
                String str = segList.get(i).get(0).content;
                if (indexInText < min){
                    min = indexInText;
                    segIndex = i;
                }

                if (i == segList.size() - 1){
                    elements.add(segList.get(segIndex).get(0).content);
                    segList.get(segIndex).remove(0);
                    if (segList.get(segIndex).size()==0){
                        countDown--;
                    }

                    min = text.length();
                }

            }
        }




        return elements;

    }


    static public List<String>  getWords(String text){
        //识别并储存单词的内容及其实索引

        List<String> wordList = new ArrayList<>();

        List<Element> words = locateWords(text);
        for (Element word:
             words) {
         wordList.add(word.content);
        }

        return wordList;
    }

    static private List<Element> locateWords(String text){
        //识别并储存单词的内容及其实索引

        List<Element> wordList = new ArrayList<>();
        String element = "";

        boolean spotConstantElement = false;
        char ch ;
        for (int i=0 ; i<text.length(); i++){
            ch = text.charAt(i);

            if ((ch > 64 && ch < 91)||(ch > 96 && ch < 123)){


                if (!spotConstantElement){
                    //开始连续元素的记录
                    spotConstantElement = true;
                    element  = ch + "";
                }else {
                    //记录连续元素
                    element += ch;
                }

            }else {
                if (spotConstantElement){
                    //中断连续元素的记录
                    spotConstantElement = false;
                    wordList.add(new Element(element,(long)i));
                    element = "";
                }

            }
        }
        return wordList;
    }

    static private List<Element> locatePunctuation(String text){
        //识别并储存单词的内容及其实索引

        List<Element> puncList = new ArrayList<>();
        String element = "";

        boolean spotConstantPunctuation = false;
        char ch ;
        for (int i=0 ; i<text.length(); i++){
            ch = text.charAt(i);

            if ((ch > 64 && ch < 91)||(ch > 96 && ch < 123)){


            }else {
                if (spotConstantPunctuation){
                    //中断连续元素的记录
                    spotConstantPunctuation = false;
                    puncList.add(new Element(element,(long)i));
                }


                if ((ch == ' ')){
                    //不记录空格
                    element = "";
                }else {
                    //记录标点符号
                    element = ch + "";
                    puncList.add(new Element(element,(long)i));
                }
            }
        }
        return puncList;
    }

    static private List<Element> locateBlanks(String text){
        //识别并储存单词的内容及其实索引

        List<Element> blankList = new ArrayList<>();
        String element = "";

        boolean spotConstantElement = false;
        char ch ;
        for (int i=0 ; i<text.length(); i++){
            ch = text.charAt(i);

            if (ch == ' '){
                if (!spotConstantElement){
                    //开始连续元素的记录
                    spotConstantElement = true;
                    element  = ch + "";
                }else {
                    //记录连续元素
                    element += ch;
                }

            }else {
                if (spotConstantElement){
                    //中断连续元素的记录
                    spotConstantElement = false;
                    blankList.add(new Element(element,(long)i));
                }
            }
        }
        return blankList;
    }
}

package com.philosjay.fileReader.elementLocator;

import com.philosjay.fileReader.Element;

import java.util.ArrayList;
import java.util.List;

public class NumberLocator extends ElementLocator{
    @Override
    public List<Element> locate(String text) {
        //识别并储存单词的内容及其原文索引

        List<Element> numList = new ArrayList<>();
        String element = "";

        boolean spotConstantNum = false;
        char ch ;
        long index =0;
        for (int i=0 ; i<text.length(); i++){
            ch = text.charAt(i);

            if (ch > 47 && ch < 58){


                if (!spotConstantNum){
                    //开始连续元素的记录
                    spotConstantNum = true;
                    element  = ch + "";

                    index = i;
                }else {
                    //记录连续元素
                    element += ch;
                }

            }else {
                if (spotConstantNum){
                    //中断连续元素的记录
                    spotConstantNum = false;
                    numList.add(new Element(element,index));
                    element = "";
                }

            }
        }

        return numList;
    }
}

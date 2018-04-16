package com.philosjay.fileReader.elementLocator;

import com.philosjay.fileReader.Element;

import java.util.ArrayList;
import java.util.List;

public class BlankLocator extends ElementLocator  {
    @Override
    public List<Element> locate(String text) {
        //识别并储存空格的内容及其原文索引

        List<Element> blankList = new ArrayList<>();
        String element = "";

        boolean spotConstantElement = false;
        char ch ;
        long index =0;
        for (int i=0 ; i<text.length(); i++){
            ch = text.charAt(i);

            if (ch == ' '){
                if (!spotConstantElement){
                    //开始连续元素的记录
                    spotConstantElement = true;
                    element  = ch + "";

                    index = i;
                }else {
                    //记录连续元素
                    element += ch;
                }

            }else {
                if (spotConstantElement){
                    //中断连续元素的记录
                    spotConstantElement = false;
                    blankList.add(new Element(element,index));
                }
            }
        }

        return blankList;
    }
}

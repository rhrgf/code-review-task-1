package com.philosjay.fileReader.elementLocator;

import com.philosjay.fileReader.Element;

import java.util.ArrayList;
import java.util.List;

public class PunctuationLocator extends ElementLocator {
    @Override
    public List<Element> locate(String text) {
        //识别并储存标点的内容及其原文索引

        List<Element> puncList = new ArrayList<>();
        String element = "";

        boolean spotConstantPunctuation = false;
        char ch ;
        for (int i=0 ; i<text.length(); i++){
            ch = text.charAt(i);

            if ((ch > 32 && ch < 48)||(ch > 57 && ch < 65)||(ch > 90 && ch < 97)||(ch > 122 && ch < 127)||(ch == 10)){

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
            }else {

            }
        }

        return puncList;
    }
}

package com.philosjay.fileReader.elementLocator;

public class ElementLocatorFactory {

    // 简单工厂，返回支持的ElementLocator
    static public ElementLocator get(String type){

        ElementLocator locator = null;
        switch (type){
            case "WordLocator":
                locator = new WordLocator();
                break;
            case "PunctuationLocator":
                locator = new PunctuationLocator();
                break;
            case "NumberLocator":
                locator = new NumberLocator();
                break;
            case "BlankLocator":
                locator = new BlankLocator();
                break;
        }
        return locator;
    }
}

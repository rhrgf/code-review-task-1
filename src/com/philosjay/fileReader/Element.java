package com.philosjay.fileReader;

public class Element {
    public String content;
    public long indexInText;

    public Element(String content,long indexInText){
        this.content = content;
        this.indexInText = indexInText;
    }
}

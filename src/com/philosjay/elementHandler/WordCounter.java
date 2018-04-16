package com.philosjay.elementHandler;

import java.util.*;

public class WordCounter {
    public List<Map.Entry<String,Integer>> countWord(List<String> elements){


        Map<String,Integer> map = new HashMap<>();

        for (int i=0; i<elements.size();i++){
            String word = elements.get(i);
            if (map.get(word) == null){
                //初次记录此word
                map.put(word,1);
            }else {
                map.put(word,map.get(word)+1);
            }
        }


        //将Map转为List，进行排序
        List<Map.Entry<String,Integer>> list = new ArrayList<Map.Entry<String,Integer>>(map.entrySet());
        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o2.getValue() - o1.getValue();
            }

        }); //重新排序

        return list;
    }

}

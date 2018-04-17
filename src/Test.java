/**
 * Created by liberty on 2018/4/10.
 */

import java.io.*;
import java.util.*;

public class Test {
    public static void main(String[] args) {
        WordHelper wordHelper = new WordHelper();
        String fileName = "words.txt";
        Map<String, Word> wordMap = new HashMap<>();

        try (FileInputStream fis = new FileInputStream(fileName);
             BufferedInputStream bis = new BufferedInputStream(fis)) {

            StringBuffer buff = new StringBuffer();
            int inByte;

            do {
                inByte = bis.read();
                char ch = (char) inByte;
                if (inByte != -1 && ch != ' ') {
                    buff.append(ch);
                } else {
                    if (wordMap.containsKey(buff.toString())) {
                        wordMap.get(buff.toString()).incCount();
                    } else {
                        Word word = new Word(buff.toString(), 1);
                        wordMap.put(buff.toString(), word);
                    }
                    buff = new StringBuffer();
                }
            } while (inByte != -1);

            bis.close();
            fis.close();

            wordHelper.sort(wordMap);
            wordHelper.displayWordsInfo(wordMap);

        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
}

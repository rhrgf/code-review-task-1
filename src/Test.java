/**
 * Created by liberty on 2018/4/10.
 */

import java.io.*;
import java.util.*;

public class Test {
    public static void main(String[] args) {
        String fileName = "words.txt";
        Map<String, Word> wordMap = new HashMap<>();

        try (FileInputStream fis = new FileInputStream(fileName);
             BufferedInputStream bis = new BufferedInputStream(fis)) {

            StringBuffer buff = new StringBuffer();
            int c;
            char ch;

            do {
                c = bis.read();
                ch = (char) c;
                if (c != -1 && ch != ' ') {
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
            } while (c != -1);

            bis.close();
            fis.close();

            List<Map.Entry<String, Word>> wordList = new ArrayList<>(wordMap.entrySet());

            /*Collections.sort(wordList, new Comparator<Map.Entry<String, Word>>() {
                @Override
                public int compare(Map.Entry<String, Word> o1, Map.Entry<String, Word> o2) {
                    int c1 = o1.getValue().getCount();
                    int c2 = o2.getValue().getCount();
                    if (c1 < c2) {
                        return -1;
                    } else if (c1 > c2) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            });*/

            Collections.sort(wordList, (o1, o2) -> {
                int c1 = o1.getValue().getCount();
                int c2 = o2.getValue().getCount();
                if (c1 < c2) {
                    return 1;
                } else if (c1 > c2) {
                    return -1;
                } else {
                    return 0;
                }
            });

            for (Map.Entry<String, Word> entry : wordList) {
                Word w = entry.getValue();
                System.out.println(w.getText() + " " + w.getCount());
            }

        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
}

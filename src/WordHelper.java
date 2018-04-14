/**
 * Created by liberty on 2018/4/14.
 */

import java.util.*;

public class WordHelper {
    public void sort(Map<String, Word> wordMap) {
        List<Map.Entry<String, Word>> wordList = new ArrayList<>(wordMap.entrySet());

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
    }

    public void displayWordsInfo(Map<String, Word> wordMap) {
        List<Map.Entry<String, Word>> wordList = new ArrayList<>(wordMap.entrySet());

        for (Map.Entry<String, Word> entry : wordList) {
            Word w = entry.getValue();
            System.out.println(w.getText() + " " + w.getCount());
        }
    }
}

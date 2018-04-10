/**
 * Created by liberty on 2018/4/10.
 */
public class Word {
    private String text;
    private int count;

    public Word() {
        text = "";
        count = 0;
    }

    public Word(String text, int count) {
        this.text = text;
        this.count = count;
    }

    public void setText(String text) {
        this.text = text;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public String getText() {
        return text;
    }

    public int getCount() {
        return count;
    }

    public void incCount() {
        count++;
    }
}

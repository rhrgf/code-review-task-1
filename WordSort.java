package wordcount;

//排序
public class WordSort implements Comparable<WordSort>{  
    @Override  
    public int compareTo(WordSort o) {  
        int cmp = count.intValue() - o.count.intValue();  
        return (cmp == 0 ? key.compareTo(o.key) : -cmp);
    }  
  
    private String key;  
    private Integer count;  
  
    public WordSort ( String key,Integer count) {  
        this.key = key;  
        this.count = count;
        }  
   
  
    public String getKey() {  
        return key;  
    }  
  
    public Integer getCount() {  
        return count;  
    }  
}  

import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class TextFileWordCount implements ITextFileHandler {
	
	private Map<String, Integer> wordFreq;
	
	public TextFileWordCount() {
		super();
		wordFreq = new HashMap<String, Integer>();
	}

	@Override
	public boolean handleTextFile(BufferedReader fileReader) {
		String line;
		boolean ret = false;
		
		try {
			while ((line = fileReader.readLine()) != null) {
				// 对各行单词按分隔符切片
				String[] strs = line.split("\\s+");
				
				// 遍历各单词，写入词频表中
				for (String word : strs) {
					// 若该单词之前已出现过，其词频自增；否则置其词频为1
					if (wordFreq.containsKey(word)) {
						wordFreq.put(word, wordFreq.get(word) + 1);
					} else {
						wordFreq.put(word, 1);
					}
				}
			}
			ret = true;
		} catch (IOException e) {
			
		}
		return ret;	
	}
	
	public Map<String, Integer> getWordFreq() {
		return wordFreq;
	}
	
	
}

package WordsCount;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class LineCountFileHandler extends FileHandler{
	
	private Map<String, Integer> wordFreq;
	
	public Map<String, Integer> GetWordFreqMap() {
		return wordFreq;
	}

	@Override
	public boolean Handle(BufferedReader reader) {
		String line;
		boolean ret = false;
		
		try {
			while ((line = reader.readLine()) != null) {
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
			lastError = ERR_IO_EXCEPTION;
		}
		return ret;	
	}
	
	public LineCountFileHandler(String path) {
		super(path);
		wordFreq = new HashMap<String, Integer>();
	}

}

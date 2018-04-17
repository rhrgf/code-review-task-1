package WordsCount;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class MainApp {
	
	public static void ShowCountResult(Map<String, Integer> wordFreq) {
		// 1. 降序排列
		List<Map.Entry<String, Integer>> wordFreqList = 
				new ArrayList<Map.Entry<String, Integer>>(wordFreq.entrySet());
		
		wordFreqList.sort((Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2)->{
			return o2.getValue() - o1.getValue();});
		// 2. 终端显示
		for (Map.Entry<String, Integer> wordCount : wordFreqList) {
			System.out.println(wordCount.getKey() + ' ' + wordCount.getValue());
		}
	}
	
	
	public static void main(String[] args) {
		LineCountFileHandler handler = new LineCountFileHandler("src//words.txt");
		if(handler.HandleFile() == true) {
			Map<String, Integer> wordFreq = handler.GetWordFreqMap();
			ShowCountResult(wordFreq);
		} else if (handler.GetLastError() == FileHandler.ERR_FILE_NOT_FOUND ) {
			System.out.println("未找到指定的文件路径");
		} else if (handler.GetLastError() == FileHandler.ERR_IO_EXCEPTION) {
			System.out.println("存取过程中发生IO异常");
		}
		
	}

}

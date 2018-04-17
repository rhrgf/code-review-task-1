import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;


public class CResultShowInConsole implements IResultShow {

	private List<Map.Entry<String, Integer>> wordFreqList;

	
	private void SortMapByValDec(Map<String, Integer> map) {
		wordFreqList = new ArrayList<Map.Entry<String, Integer>>(map.entrySet());
		wordFreqList.sort((Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2)->{
			return o2.getValue() - o1.getValue();});
	}
	
	@Override
	public void ShowResult(Map<String, Integer> map) {
		SortMapByValDec(map);
		for (Map.Entry<String, Integer> wordCount : wordFreqList) {
			System.out.println(wordCount.getKey() + ' ' + wordCount.getValue());
		}
	}

}

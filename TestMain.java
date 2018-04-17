package wordcount;

import static org.junit.Assert.*;

import java.io.File;

import javax.print.DocFlavor.INPUT_STREAM;

import org.junit.Test;

public class TestMain {

	@Test
	public void test() {
		String datafile1 = new File("").getAbsolutePath() + File.separator + "LICENSE.txt";//正确路径
		String datafile2 = new File("").getAbsolutePath() + File.separator + "LICENSE1.txt";//不存在文件
		WordCount t = new WordCount();
		t.Count(datafile1);
		t.Count(datafile2);		 
	}
}

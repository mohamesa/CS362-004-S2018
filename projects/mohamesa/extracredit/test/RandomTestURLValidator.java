import junit.framework.TestCase;
import java.util.Random;

public class RandomTestURLValidator  extends TestCase{
  private boolean printStatus = false;
  private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

  ResultPair[] testUrlScheme = {new ResultPair("http://", true),
          new ResultPair("ftp://", true),
          new ResultPair("h3t://", true),
          new ResultPair("3ht://", false),
          new ResultPair("http:/", false),
          new ResultPair("http:", false),
          new ResultPair("http/", false),
          new ResultPair("://", false),
          new ResultPair("", true)};

ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
             new ResultPair("go.com", true),
             new ResultPair("go.au", true),
             new ResultPair("0.0.0.0", true),
             new ResultPair("255.255.255.255", true),
             new ResultPair("256.256.256.256", false),
             new ResultPair("255.com", true),
             new ResultPair("1.2.3.4.5", false),
             new ResultPair("1.2.3.4.", false),
             new ResultPair("1.2.3", false),
             new ResultPair(".1.2.3.4", false),
             new ResultPair("go.a", false),
            new ResultPair("go.a1a", false),
             new ResultPair("go.1aa", false),
             new ResultPair("aaa.", false),
             new ResultPair(".aaa", false),
             new ResultPair("aaa", false),
             new ResultPair("", false)
};
ResultPair[] testUrlPort = {new ResultPair(":80", true),
        new ResultPair(":65535", true),
        new ResultPair(":0", true),
        new ResultPair("", true),
        new ResultPair(":-1", false),
       new ResultPair(":65636",false),
        new ResultPair(":65a", false)
};
ResultPair[] testPath = {new ResultPair("/test1", true),
     new ResultPair("/t123", true),
     new ResultPair("/$23", true),
     new ResultPair("/..", false),
     new ResultPair("/../", false),
     new ResultPair("/test1/", true),
     new ResultPair("", true),
     new ResultPair("/test1/file", true),
     new ResultPair("/..//file", false),
     new ResultPair("/test1//file", false)
};
//Test allow2slash, noFragment
ResultPair[] testUrlPathOptions = {new ResultPair("/test1", true),
               new ResultPair("/t123", true),
               new ResultPair("/$23", true),
               new ResultPair("/..", false),
               new ResultPair("/../", false),
               new ResultPair("/test1/", true),
               new ResultPair("/#", false),
               new ResultPair("", true),
               new ResultPair("/test1/file", true),
               new ResultPair("/t123/file", true),
               new ResultPair("/$23/file", true),
               new ResultPair("/../file", false),
               new ResultPair("/..//file", false),
               new ResultPair("/test1//file", true),
               new ResultPair("/#/file", false)
};

ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
         new ResultPair("?action=edit&mode=up", true),
         new ResultPair("", true)
};

 public void testManualTest()
 {

     
 }
   
   
   public void testIsValid()
   {
		 UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		 // create instance of Random class
	     Random rnd = new Random(); 
	     
	     //count how many value pairs are there in each resultPair
	     int cnt_testUrlScheme = testUrlScheme.length;
	     int cnt_testUrlAuthority = testUrlAuthority.length;
	     int cnt_testUrlPort = testUrlPort.length;
	     int cnt_testPath = testPath.length;
	     int cnt_testUrlPathOptions = testUrlPathOptions.length;
	     int cnt_testUrlQuery = testUrlQuery.length;
	     	     
	     for(int i = 0;i<1000;i++)
	     {
		     //Default valid value
	    	 Boolean UrlShouldBeValid = true;
	    	 Boolean retVal = false;
	    	 String passOrFail = "";
	    	 
	    	 //generate random numbers for the index of each resultPair
		     int rnd_testUrlScheme = rnd.nextInt(cnt_testUrlScheme);
		     int rnd_testUrlAuthority = rnd.nextInt(cnt_testUrlAuthority);
		     int rnd_testUrlPort = rnd.nextInt(cnt_testUrlPort);
		     int rnd_testPath = rnd.nextInt(cnt_testPath);
		     int rnd_testUrlPathOptions = rnd.nextInt(cnt_testUrlPathOptions);
		     int rnd_testUrlQuery = rnd.nextInt(cnt_testUrlQuery);

		     //create a URL using the random index of each result pair
		     String UrlToTest = testUrlScheme[rnd_testUrlScheme].item 
		    		 + testUrlAuthority[rnd_testUrlAuthority].item
		    		 + testUrlPort[rnd_testUrlPort].item
		    		 + testPath[rnd_testPath].item
		    		 + testUrlPathOptions[rnd_testUrlPathOptions].item
		    		 + testUrlQuery[rnd_testUrlQuery].item;
		     
		     //check if the combination is supposed to be valid or not: Unary test. only updates the boolean if value is false
		     UrlShouldBeValid = (testUrlScheme[rnd_testUrlScheme].valid == true) ? UrlShouldBeValid : testUrlScheme[rnd_testUrlScheme].valid;
		     UrlShouldBeValid = (testUrlAuthority[rnd_testUrlAuthority].valid == true) ? UrlShouldBeValid : testUrlAuthority[rnd_testUrlAuthority].valid;
		     UrlShouldBeValid = (testUrlPort[rnd_testUrlPort].valid == true) ? UrlShouldBeValid : testUrlPort[rnd_testUrlPort].valid;
		     UrlShouldBeValid = (testPath[rnd_testPath].valid == true) ? UrlShouldBeValid : testPath[rnd_testPath].valid;
		     UrlShouldBeValid = (testUrlPathOptions[rnd_testUrlPathOptions].valid == true) ? UrlShouldBeValid : testUrlPathOptions[rnd_testUrlPathOptions].valid;
		     UrlShouldBeValid = (testUrlQuery[rnd_testUrlQuery].valid == true) ? UrlShouldBeValid : testUrlQuery[rnd_testUrlQuery].valid;
		     
		     //test the URL and return the result
		     retVal = urlVal.isValid(UrlToTest);

		     //Check the return value to what should be
		     passOrFail = (retVal == UrlShouldBeValid) ? "Pass" : "Fail";
		     
		     //Print out the result
		     System.out.println("Test result: " + passOrFail + " - Value Returned: " + retVal + " - Value Expected: " + UrlShouldBeValid + " - URL tested: " + UrlToTest);
	     }
   }
   
   
}

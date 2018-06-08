

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {
   private UrlValidator validator = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
   private PartitionTester partitionTester = new PartitionTester();
   private AutoTester autoTester = new AutoTester();

 public UrlValidatorTest(String testName) {
	  super(testName);
 }

   public void testManualTest()  {
	  
   UrlValidator urlVal = new UrlValidator();
   //Default valid value
   Boolean UrlShouldBeValid = true;
   Boolean valueReturned = true;
   Boolean validation;
   String passOrFail = "";
   
   System.out.println("\n############### BEGIN MANUAL TEST ###############");
   UrlShouldBeValid = true;
   valueReturned = urlVal.isValid("http://www.ebay.com");
   validation= valueReturned == UrlShouldBeValid;
   //Check the return value to what should be
   passOrFail = (validation == true) ? "Pass" : "Fail";
   System.out.println("Test result 1: " + passOrFail + " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);

   UrlShouldBeValid = true;
   valueReturned = urlVal.isValid("ftp://www.ebay.com");
   validation = valueReturned == UrlShouldBeValid;
   //Check the return value to what should be
   passOrFail = (validation == UrlShouldBeValid) ? "Pass" : "Fail";
   System.out.println("Test result 2: " + passOrFail + " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);

   UrlShouldBeValid = true;
   valueReturned = urlVal.isValid("http://0.0.0.0/$23/test1/?action=edit&mode=up");
   validation = valueReturned == UrlShouldBeValid;
   //Check the return value to what should be
   passOrFail = (validation == UrlShouldBeValid) ? "Pass" : "Fail";
   System.out.println("Test result 3: " + passOrFail + " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);
   
   UrlShouldBeValid = true;
   valueReturned = urlVal.isValid("http://go.au:80/test1/?action=edit&mode=up");
   validation = valueReturned == true;
   //Check the return value to what should be
   passOrFail = (validation == UrlShouldBeValid) ? "Pass" : "Fail";
   System.out.println("Test result 4: " + passOrFail + " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);
   
    
   UrlShouldBeValid = true;
   valueReturned = urlVal.isValid("http://0.0.0.0/$23/test1/?action=edit&mode=up");
   validation= valueReturned == UrlShouldBeValid;
   //Check the return value to what should be
   passOrFail = (validation == UrlShouldBeValid) ? "Pass" : "Fail";
   System.out.println("Test result 5: " + passOrFail + " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);
   
   // inVaild URL
   
   UrlShouldBeValid = false;
   valueReturned = urlVal.isValid("255.com:80/../test1//file?action=edit&mode=up");
   validation = valueReturned == UrlShouldBeValid;
   //Check the return value to what should be
   passOrFail = ( validation == true) ? "Pass" : "Fail";
   System.out.println("Test result 6: " + passOrFail + " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);
  
   UrlShouldBeValid = false;
   valueReturned = urlVal.isValid("http:/www.ebay.com");
   validation = valueReturned == UrlShouldBeValid;
   //Check the return value to what should be
   passOrFail = (  validation == true) ? "Pass" : "Fail";
   System.out.println("Test result 7: " + passOrFail+ " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);
  
   UrlShouldBeValid = false;
   valueReturned = urlVal.isValid("http://www.ebay.com//8");
   validation = valueReturned == UrlShouldBeValid;
   //Check the return value to what should be
   passOrFail = (validation == true) ? "Pass" : "Fail";
   System.out.println("Test result 8: " + passOrFail  + " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);
  
   UrlShouldBeValid = false;
   valueReturned = urlVal.isValid("http://.www.ebay.com");
   validation = valueReturned == UrlShouldBeValid;
   //Check the return value to what should be
   passOrFail = (validation == true) ? "Pass" : "Fail";
   System.out.println("Test result 9: " + passOrFail + " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);
   
   UrlShouldBeValid = false;
   validation = urlVal.isValid("3ht://ebay.com");
   validation = valueReturned == UrlShouldBeValid;
   //Check the return value to what should be
   passOrFail = (validation == true) ? "Pass" : "Fail";
   System.out.println("Test result 10: " + passOrFail + " - Value Returned: " + valueReturned + " - Value Expected: " + UrlShouldBeValid);
   System.out.println("############### END MANUAL TEST ###############");
   System.out.println("\n"); 
   
  }  
   public void testSchemePartition(){
	  TestPair next;
      next = partitionTester.getNextSchemePartition();
      int failures = 0;
      while(next != null){
         boolean result = validator.isValid(next.toString());
         if (result != next.isValid()){
            System.out.println("Fail on URL: " + next.toString());
            System.out.println("\tisValid: " + result + ". Expected: " + next.isValid());
            failures++;
         }
         next = partitionTester.getNextSchemePartition();
      }
      if (failures > 0){
         System.out.println("Finished test of Scheme Partitions with " + failures + " failures.");
      }
      else{
         System.out.println("Passed Test of Scheme Partitions!");
      }
   }

   public void testAuthorityPartition(){
      TestPair next;
      next = partitionTester.getNextAuthorityPartition();
      int failures = 0;
      while(next != null){
         boolean result = validator.isValid(next.toString());
         if (result != next.isValid()){
            System.out.println("Fail on URL: " + next.toString());
            System.out.println("\tisValid: " + result + ". Expected: " + next.isValid());
            failures++;
         }
         next = partitionTester.getNextAuthorityPartition();
      }
      if (failures > 0){
         System.out.println("Finished test of Authority Partitions with " + failures + " failures.");
      }
      else{
         System.out.println("Passed Test of Authority Partitions!");
      }
   }

   public void testPathPartition(){
      TestPair next;
      next = partitionTester.getNextPathPartition();
      int failures = 0;
      while(next != null){
         boolean result = validator.isValid(next.toString());
         if (result != next.isValid()){
            System.out.println("Fail on URL: " + next.toString());
            System.out.println("\tisValid: " + result + ". Expected: " + next.isValid());
            failures++;
         }
         next = partitionTester.getNextPathPartition();
      }
      if (failures > 0){
         System.out.println("Finished test of Path Partitions with " + failures + " failures.");
      }
      else{
         System.out.println("Passed Test of Path Partitions!");
      }
   }

   public void testQueryPartition(){
      TestPair next;
      next = partitionTester.getNextQueryPartition();
      int failures = 0;
      while(next != null){
         boolean result = validator.isValid(next.toString());
         if (result != next.isValid()){
            System.out.println("Fail on URL: " + next.toString());
            System.out.println("\tisValid: " + result + ". Expected: " + next.isValid());
            failures++;
         }
         next = partitionTester.getNextQueryPartition();
      }
      if (failures > 0){
         System.out.println("Finished test of Query Partitions with " + failures + " failures.");
      }
      else{
         System.out.println("Passed Test of Query Partitions!");
      }
   }

   public void testFragmentPartition(){
      TestPair next;
      next = partitionTester.getNextFragmentPartition();
      int failures = 0;;
      while(next != null){
         boolean result = validator.isValid(next.toString());
         if (result != next.isValid()){
            System.out.println("Fail on URL: " + next.toString());
            System.out.println("\tisValid: " + result + ". Expected: " + next.isValid());
            failures++;
         }
         next = partitionTester.getNextFragmentPartition();
      }
      if (failures > 0){
         System.out.println("Finished test of Fragment Partitions with " + failures + " failures.");
      }
      else{
         System.out.println("Passed Test of Fragment Partitions!");
      }
   }

   public void testIsValid()
   {
       TestPair next;
       next = autoTester.getNextTestPair();
       int failures = 0;;
       while(next != null){
           try {
               boolean result = validator.isValid(next.toString());
               if (result != next.isValid()) {
                   System.out.println("Fail on URL: " + next.toString());
                   System.out.println("\tisValid: " + result + ". Expected: " + next.isValid());
                   failures++;
               }
           }
           catch(ExceptionInInitializerError e){
               System.out.println("Fail on URL: " + next.toString());
               System.out.println("\tExceptionInInitializerError should not occur");
               failures++;
           }
           catch(NoClassDefFoundError f){
               System.out.println("Fail on URL: " + next.toString());
               System.out.println("\tNoClassDefFoundError exception should not occur");
               failures++;
           }
           next = autoTester.getNextTestPair();
       }
       if (failures > 0){
           System.out.println("Finished automatic test with " + failures + " failures.");
       }
       else{
           System.out.println("Passed automatic test!");
       }
   }
   
   public static void main(String[] argv){
      UrlValidatorTest urlTester = new UrlValidatorTest("Final Project Test");
      System.out.println("\n############### BEGIN PARTITION TEST ###############");
      urlTester.testSchemePartition();
      urlTester.testAuthorityPartition();
      urlTester.testPathPartition();
      urlTester.testQueryPartition();
      urlTester.testFragmentPartition();
      System.out.println("############### END PARTITION TEST ###############");


      System.out.println("\n############### BEGIN AUTOMATIC TEST ###############");
      urlTester.testIsValid();
      System.out.println("############### END AUTOMATIC TEST ###############");
   }

}

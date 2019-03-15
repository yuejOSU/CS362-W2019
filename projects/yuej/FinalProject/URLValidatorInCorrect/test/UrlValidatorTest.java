

import junit.framework.TestCase;

import java.util.Random;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }

    String[] validSchemes = new String[] {"http://", "ftp://", "https://"};
    String[] invalidSchemes = new String[] {"3ht://", "http:/", "http/", "://", "", "h3t://"};
    String[] validAuthorities = new String[] {"www.amazon.com", "amazon.au", "255.255.255.255"};
    String[] invalidAuthorities = new String[] {"amazon.ckaso", "", "aaa", "1.2.3.4.5"};
    String[] validPorts = new String[] {":80", ":65535", ":0", ""};
    String[] invalidPorts = new String[] {":alkj", "80aewt", ":-5"};
    String[] validPaths = new String[] {"/test", "/564543", "/test", "", "/test/file"};
    String[] invalidPaths = new String[] {"//test", "/test//file", "/.../"};
    String[] validQueries = new String[] {"", "?action=view"};

    Random rand = new Random();

   //test 8 valid strings and 8 invalid strings
   public void testManualTest()
   {
    int checker = 0; //initialize variable to keep track of number of failures
    UrlValidator URL = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("*************************************MANUAL TEST******************************************\n");
    String Valid1 = "http://go.com/test1?action=view";
    String Valid2 = "http://www.12345.com";
    String Valid3 = "http://www.google.com";
    String Valid4 = "http://store.google.com/category";
    String Valid5 = "http:/www.fortnitetracker.com";
    String Valid6 = "http://store.google.com/?utm_source=hp_header&utm_medium=google_oo&utm_campaign=GS100042";
    String Valid7 = "http://www.google.com/gmail";
    String Valid8 = "http://stackoverflow.com/questions";

    String Invalid1 = "324fasdf.m";
    String Invalid2 = "ww/.mail.com";
    String Invalid3 = "http://www.gmail.com//10";
    String Invalid4 = "hpp:.www.gmail.com";
    String Invalid5 = "http://256.256.256.256:80/test?action=view";
    String Invalid6 = "http://236.216.276.216:80/test?action=view";
    String Invalid7 = "http://gmail.com/..";
    String Invalid8 = "//gmail.com";


    //valid strings
    if(URL.isValid(Valid1)) {
      System.out.println("ASSERT PASSED - string 1 is valid!");
      assertEquals(URL.isValid(Valid1), true);
    }
    else {
        System.out.println("ASSERT FAILED - string 1 is not valid!");
      checker++;
    }

    if(URL.isValid(Valid2)) {
        System.out.println("ASSERT PASSED - string 2 is valid!");
      assertEquals(URL.isValid(Valid2), true);
    }
    else {
        System.out.println("ASSERT FAILED - string 2 is not valid!");
      checker++;
    }

    if(URL.isValid(Valid3)) {
        System.out.println("ASSERT PASSED - string 3 is valid!");
      assertEquals(URL.isValid(Valid3), true);
    }
    else {
        System.out.println("ASSERT FAILED - string 3 is not valid!");
      checker++;
    }

    if(URL.isValid(Valid4)) {
        System.out.println("ASSERT PASSED - string 4 is valid!");
      assertEquals(URL.isValid(Valid4), true);
    }
    else {
        System.out.println("ASSERT FAILED - string 4 is not valid!");
      checker++;
    }

    if(URL.isValid(Valid5)) {
        System.out.println("ASSERT PASSED - string 5 is valid!");
      assertEquals(URL.isValid(Valid5), true);
    }
    else {
        System.out.println("ASSERT FAILED - string 5 is not valid!");
      checker++;
    }

    if(URL.isValid(Valid6)) {
        System.out.println("ASSERT PASSED - string 6 is valid!");
      assertEquals(URL.isValid(Valid6), true);
    }
    else {
        System.out.println("ASSERT FAILED - string 6 is not valid!");
      checker++;
    }

    if(URL.isValid(Valid7)) {
        System.out.println("ASSERT PASSED - string 7 is valid!");
      assertEquals(URL.isValid(Valid7), true);
    }
    else {
        System.out.println("ASSERT FAILED - string 7 is not valid!");
      checker++;
    }

    if(URL.isValid(Valid8)) {
        System.out.println("ASSERT PASSED - string 8 is valid!");
      assertEquals(URL.isValid(Valid8), true);
    }
    else {
      System.out.println("ASSERT FAILED - string 8 is not valid!");
      checker++;
    }

    //invalid strings
    if(URL.isValid(Invalid1)) {
        System.out.println("ASSERT FAILED - string 9 is valid!");
      checker++;
    }
    else {
      assertFalse(URL.isValid(Invalid1));
        System.out.println("ASSERT PASSED - string 9 is not valid!");
    }

    if(URL.isValid(Invalid2)) {
        System.out.println("ASSERT FAILED - string 10 is valid!");
      checker++;
    }
    else {
      assertFalse(URL.isValid(Invalid2));
        System.out.println("ASSERT PASSED - string 10 is not valid!");
    }

    if(URL.isValid(Invalid3)) {
        System.out.println("ASSERT FAILED - string 11 is valid!");
      checker++;
    }
    else {
      assertFalse(URL.isValid(Invalid3));
        System.out.println("ASSERT PASSED - string 11 is not valid!");
    }

    if(URL.isValid(Invalid4)) {
        System.out.println("ASSERT FAILED - string 12 is valid!");
      checker++;
    }
    else {
      assertFalse(URL.isValid(Invalid4));
        System.out.println("ASSERT PASSED - string 12 is not valid!");
    }

    if(URL.isValid(Invalid5)) {
        System.out.println("ASSERT FAILED - string 913 is valid!");
      checker++;
    }
    else {
      assertFalse(URL.isValid(Invalid5));
        System.out.println("ASSERT PASSED - string 13 is not valid!");
    }

    if(URL.isValid(Invalid6)) {
        System.out.println("ASSERT FAILED - string 14 is valid!");
      checker++;
    }
    else {
      assertFalse(URL.isValid(Invalid6));
        System.out.println("ASSERT PASSED - string 14 is not valid!");
    }

    if(URL.isValid(Invalid7)) {
        System.out.println("ASSERT FAILED - string 15 is valid!");
      checker++;
    }
    else {
        System.out.println("ASSERT PASSED - string 15 is not valid!");
    }

    if(URL.isValid(Invalid8)) {
        System.out.println("ASSERT FAILED - string 16 is valid!");
      checker++;
    }
    else {
      assertFalse(URL.isValid(Invalid7));
      System.out.println("ASSERT PASSED - string 16 is not valid!");
    }

    if(checker > 0) {
      System.out.println("\nManual Testing Failed " + checker + " times!");
    }
    else {
      System.out.println("\nManual Testing Passed " + (16 - checker) + " times!");
    }

       System.out.println("****************************************END TEST******************************************\n");


   }

   public void testYourFirstPartition() {
        UrlValidator URL = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String completeString = "";
        String scheme = "";
        String authority = "";
        String port = "";
        String path = "";
        String query = "";
        //getting random number from 0 - 3
        int randomSchemes = rand.nextInt(1);
        if (randomSchemes != 3)
            scheme = validSchemes[randomSchemes];

        //getting random number from 0 - 2
        int randomAuthorities = rand.nextInt(3);
        if (randomAuthorities != 3)
            authority = validAuthorities[randomAuthorities];

        // get whether insert port or path
        int rand_num = rand.nextInt(2);
        if (rand_num == 0) {
            //getting random number from 0 - 4
            int randomPorts = rand.nextInt(5);
            if (randomPorts != 4)
                port = validPorts[randomPorts];

            completeString = scheme + authority + port;
        } else {
            //getting random number from 0 - 5
            int randomPaths = rand.nextInt(6);
            if (randomPaths != 5) {
                path = validPaths[randomPaths];

                //getting random number from 0 - 2
                int randomQueries = rand.nextInt(3);
                if (randomQueries != 2)
                    query = validQueries[randomQueries];
            }

            completeString = scheme + authority + path + query;
        }
        System.out.println("************************************RANDOM TEST******************************************\n");

        System.out.println(completeString + "\n");
        //assertEquals(URL.isValid(completeString), true);

        if (URL.isValid(completeString)) {
            System.out.println("RANDOM STRING PASSES ASSERTION!");
        } else {
            assertFalse(URL.isValid(completeString));
            System.out.println("RANDOM STRING FAILS TO PASS ASSERTION!");
        }
        System.out.println("\n***************************************END TEST******************************************\n");

    }

    // helper function for programming based testing
    private void GlobalUrlTester(UrlValidator URL, String pre, String post, String[] validPart, String[] invalidPart)
    {
        boolean checker = true;

        for(int i = 0; i < validPart.length; i++ )
        {
            String validURL = "http://" + pre + validPart[i] + post;

            if (URL.isValid(validURL))
            {
                assertEquals(URL.isValid(validURL), true);
                System.out.println("TEST PASSED - CONFIRMS VALID: " + validURL);
            }
            else if(!URL.isValid(validURL)){
                assertEquals(URL.isValid(validURL), false);
                System.out.println("TEST FAILED - Valid input is interpreted as Invalid: " + validURL);
                checker = false;

            }
            else {
                assertEquals(URL.isValid(validURL), false);
                System.out.println("TEST PASSED - CONFIRMS INVALID: " + validURL);
            }
        }

        for(int i = 0; i < invalidPart.length; i++ )
        {
            String invalidURL = "http://" + pre + invalidPart[i] + post;

            if (URL.isValid(invalidURL))
            {
                assertEquals(URL.isValid(invalidURL), true);
                System.out.println("TEST FAILED - Invalid inout is interpreted as Valid: " + invalidURL);
                checker = false;

            }
            else {
                assertFalse(URL.isValid(invalidURL));

                System.out.println("TEST PASSED - CONFIRMS INVALID: " + invalidURL);
            }
        }

        if(checker)
        {
            System.out.println("\nALL TESTS PASS!");
        }
        else{
            System.out.println("\nNOT ALL TESTS PASS!");

        }

    }

   // programming based testing 1
   public void testIsValidAuthority(){

       UrlValidator URL = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);


       String[] validUrlPart = {
               "www.google.com",
               "go.com",
               "0.0.0.0",
               "go.cc",
               "255.255.255.255",
               "255.com"
       };

       String[] invalidUrlPart = {
               "amazon.INVALID",
               "1.2.3.4.5",
               "256.256.256.2",
               "google.www.255.com",
               "aaAa",
               ""
       };

       System.out.println("\n***************************TESTING isValidAUTHORITY() FUNCTION****************************");

       GlobalUrlTester(URL, "", "", validUrlPart, invalidUrlPart);

       System.out.println("***************************************END TEST*******************************************\n");
   }

   // programming based testing 2
   public void testIsValidPath(){

       UrlValidator URL = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

       String[] validPaths = {
               "/test1",
               "/t123",
               "/test1/",
               "/$23",
               "",
               "/test1/file"

       };

       String[] invalidPaths = {
               "/..",
               "/../",
               "/../file",
               "/..//file",
       };

       System.out.println("\n*****************************TESTING isValidPATH() FUNCTION*******************************");

       GlobalUrlTester(URL, "www.amazon.com", "", validPaths, invalidPaths);

       System.out.println("***************************************END TEST*******************************************\n");
   }

    // programming based testing 3
    public void testIsValidPort(){

        UrlValidator URL = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        String[] validPorts = new String[] {":80", ":65535", ":0", ""};

        String[] invalidPorts = {":65536", ":-1", ":65636", ":999999999999999999", ":65a"};

        System.out.println("\n****************************TESTING isValidPORT() FUNCTION*******************************");

        GlobalUrlTester(URL, "www.amazon.com", "", validPorts, invalidPorts);

        System.out.println("***************************************END TEST******************************************\n");
    }

}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/AdmissionEligibilityTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class AdmissionEligibilityTest {

    AdmissionEligibility obj = new AdmissionEligibility();

    @Test
    public void testEligibleByTotal() {
        assertTrue(obj.isEligible(60, 50, 50)); // total = 160
    }

   @Test
public void testEligibleByMathsPhysics() {
    assertTrue(obj.isEligible(70, 50, 50)); // M+P = 120 and all subjects valid
}
    @Test
    public void testNotEligibleLowMaths() {
        assertFalse(obj.isEligible(50, 60, 60));
    }

    @Test
    public void testNotEligibleLowPhysics() {
        assertFalse(obj.isEligible(70, 40, 60));
    }

    @Test
    public void testNotEligibleLowChemistry() {
        assertFalse(obj.isEligible(70, 60, 40));
    }

    @Test
    public void testNotEligibleTotalConditionFail() {
        assertFalse(obj.isEligible(60, 50, 45)); // total < 160 & M+P < 120
    }

    @Test
    public void testHonorsEligible() {
        assertTrue(obj.isHonors(80, 80, 70)); // total = 230
    }

    @Test
    public void testEligibleButNotHonors() {
        assertFalse(obj.isHonors(70, 60, 50)); // total = 180
    }
}
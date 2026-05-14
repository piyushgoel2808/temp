package stlab.p19;

import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class EligibilityServiceTest {
    private final EligibilityService service = new EligibilityService();

    @Test
    public void eligibleByTotalRule() {
        Candidate candidate = new Candidate(70, 55, 40);
        assertFalse(service.isEligible(candidate));

        Candidate eligible = new Candidate(70, 55, 50);
        assertTrue(service.isEligible(eligible));
    }

    @Test
    public void eligibleByMathPhysicsRule() {
        Candidate candidate = new Candidate(80, 45, 30);
        assertTrue(service.isEligible(candidate));
    }

    @Test
    public void honorsWhenTotalAbove225() {
        Candidate candidate = new Candidate(90, 80, 60);
        assertTrue(service.isHonors(candidate));
    }
}

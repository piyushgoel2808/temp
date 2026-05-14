package stlab.p19;

public class EligibilityService {
    public boolean isEligible(Candidate candidate) {
        if (candidate == null) {
            return false;
        }
        int math = candidate.getMathematics();
        int physics = candidate.getPhysics();
        int chemistry = candidate.getChemistry();
        int total = candidate.getTotal();

        boolean ruleA = math >= 60 && physics >= 50 && chemistry >= 50 && total >= 160;
        boolean ruleB = (math + physics) >= 120;
        return ruleA || ruleB;
    }

    public boolean isHonors(Candidate candidate) {
        return isEligible(candidate) && candidate.getTotal() > 225;
    }
}

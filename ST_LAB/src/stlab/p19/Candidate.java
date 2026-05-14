package stlab.p19;

public class Candidate {
    private final int mathematics;
    private final int physics;
    private final int chemistry;

    public Candidate(int mathematics, int physics, int chemistry) {
        this.mathematics = mathematics;
        this.physics = physics;
        this.chemistry = chemistry;
    }

    public int getMathematics() {
        return mathematics;
    }

    public int getPhysics() {
        return physics;
    }

    public int getChemistry() {
        return chemistry;
    }

    public int getTotal() {
        return mathematics + physics + chemistry;
    }
}

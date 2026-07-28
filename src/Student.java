import java.util.Set;

public class Student {
    private String name;
    private int id;
    private Set<Unit> completedUnits;

    public Student(String name, int id, Set<Unit> completedUnits) {
        this.name = name;
        this.id = id;
        this.completedUnits = completedUnits;
    }

    //check if the student has completed a specific unit
    public boolean hasCompleted(Unit unit) {
        return completedUnits.contains(unit);
    }

    //getters
    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public Set<Unit> getCompletedUnits() {
        return completedUnits;
    }

    //setters
    public void setName(String name) {
        this.name = name;
    }

    public void setId(int id) {
        this.id = id;
    }
}

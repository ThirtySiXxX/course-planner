public class PlannedUnit {
    private Unit unit;
    private TeachingPeriod teachingPeriod;
    private boolean force; //if true, student can take this unit regardless of other requirements
    int year; //the year the student plans to take this unit

    public PlannedUnit(Unit unit, TeachingPeriod teachingPeriod, int year, boolean force) {
        this.unit = unit;
        this.teachingPeriod = teachingPeriod;
        this.year = year;
        this.force = force;
        
    }

    //getters
    public Unit getUnit() {
        return unit;
    }

    public TeachingPeriod getTeachingPeriod() {
        return teachingPeriod;
    }

    public boolean isForced() {
        return force;
    }

    public int getYear() {
        return year;
    }

    //setters
    public void setUnit(Unit unit) {
        this.unit = unit;
    }

    public void setTeachingPeriod(TeachingPeriod teachingPeriod) {
        this.teachingPeriod = teachingPeriod;
    }

    public void setForce(boolean force) {
        this.force = force;
    }

    public void setYear(int year) {
        this.year = year;
    }

}
// Defines the grinder interface and a blade grinder.
// The brew cycle uses the interface to request a dose.

#pragma once

enum class GrindSize { Fine, Medium, Coarse };

class Grinder {
   public:
    virtual ~Grinder() = default;

    virtual int grind(int gramsRequested, GrindSize size) = 0;

    virtual GrindSize lastSize() const = 0;
};

class BladeGrinder : public Grinder {
   public:
    int grind(int gramsRequested, GrindSize size) override;
    GrindSize lastSize() const override { return last_size_; }

   private:
    GrindSize last_size_ = GrindSize::Medium;
};

//
// Created by kyle on 9/24/20.
//

#include "random.hh"

#include "doomstat.hh"

namespace rando
{

Rng rng;

int p_random(PrClass cls)
{
    int compat = 0;
    if (cls == PrClass::Misc)
    {
        rng.pRandIndex = (rng.pRandIndex + 1) & 255;
        compat = rng.pRandIndex;
    }
    else
    {
        rng.randIndex = (rng.randIndex + 1) & 255;
        compat = rng.randIndex;
    }
    if (cls != PrClass::Misc && doomstat::demo_insurance == doomstat::DemoInsurance::Never)
    {
        cls = PrClass::AllInOne;
    }

    std::size_t boom = rng.seed[static_cast<std::size_t>(cls)];
    // advance seed
    rng.seed[static_cast<std::size_t>(cls)] = boom * 1664525UL + 221297UL + static_cast<std::size_t>(cls) * 2;

    if (doomstat::demo_compatibility())
    {
        return RANDOM_TABLE[compat];
    }

    boom >>= 20;
    if (doomstat::demo_insurance != doomstat::DemoInsurance::Never)
    {
        boom += (doomstat::gametic - doomstat::basetic) * 7;
    }

    return static_cast<int>(boom & 255);
}

} // namespace rando

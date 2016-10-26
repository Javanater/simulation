//
// Created by Madison on 8/30/2016.
//

#ifndef PROJECTS_INTERSECTIONCALCULATOR_HPP
#define PROJECTS_INTERSECTIONCALCULATOR_HPP

#include <Math/geometry/Ray.h>
#include "Intersectable.h"
#include <set>

namespace flabs
{
	template<uint32_t DIM, class TYPE = double>
	class IntersectionCalculator
	{
		private:
			std::set<Intersectable*> intersectables;

		public:
			typedef Ray<DIM, TYPE> Ry;

			void addIntersectable(Intersectable& intersectable)
			{
				intersectables.insert(&intersectable);
			}

			/**
			 * Returns the distance to the closest intersectable object. If no
			 * object is hit, then std::numeric_limits<TYPE>::infinity() is
			 * returned.
			 *
			 * @param ray
			 * @return
			 */
			TYPE distance(Ry& ray) const
			{
				TYPE closestDistance = std::numeric_limits<TYPE>::infinity();
				for (Intersectable* intersectable : intersectables)
				{
					TYPE currentDistance;
					if (intersectable->distance(&ray, currentDistance) ==
						INTERSECT && currentDistance < closestDistance)
						closestDistance = currentDistance;
				}
				return closestDistance;
			}
	};
}

#endif //PROJECTS_INTERSECTIONCALCULATOR_HPP

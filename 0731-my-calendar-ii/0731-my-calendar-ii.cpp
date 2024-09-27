class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapBookings;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Check for overlap with already double-booked intervals
        for (const auto& booking : overlapBookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                return false;
            }
        }

        // Check for overlap with existing single bookings and add to overlapBookings if necessary
        for (const auto& booking : bookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                overlapBookings.emplace_back(getOverlapped(booking.first, booking.second, start, end));
            }
        }

        // Add the new booking
        bookings.emplace_back(start, end);
        return true;
    }

private:
    // Helper function to check if two intervals overlap
    bool doesOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    // Helper function to calculate the overlapping interval
    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }
};

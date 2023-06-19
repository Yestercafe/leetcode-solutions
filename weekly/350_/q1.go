func distanceTraveled(mainTank int, additionalTank int) (ans int) {
    for mainTank >= 5 {
        mainTank -= 5
        ans += 5
        if additionalTank > 0 {
            additionalTank--
            mainTank++
        }
    }
    ans += mainTank
    ans *= 10
    return
}


library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- Test Bench: compteur --

architecture behavioral of compteur_tb is

component compteur_tb is
    port ( clk : in STD_LOGIC;
           valid : in STD_LOGIC;
           raz : in STD_LOGIC;
           TTL_mef : in STD_LOGIC;
           freq : out STD_LOGIC_VECTOR(15 downto 0));
end component compteur_tb;

signal clk : STD_LOGIC := '0';
signal valid : STD_LOGIC := '0';
signal raz : STD_LOGIC := '0';
signal TTL_mef : STD_LOGIC := '0';

signal freq : STD_LOGIC_VECTOR(15 downto 0);

begin
    -- device under test --
    dut : compteur_tb PORT MAP(clk => clk, valid => valid, raz => raz, TTL_mef => TTL_mef, freq => freq);

p1 : process -- Horloge 100 MHz / 10ns --
begin
    clk <= '0';
    wait for 5 ns;
    clk <= '1';
    wait for 5 ns;
end process;

p2 : process -- TTL_mef signal --
begin
    TTL_mef <= '0';
    wait for 100 ns;
    TTL_mef <= '1';
    wait for 10 ns;
end process;

p3 : process -- raz signal --
begin
    raz <= '0';
    wait for 1000 ms;
    ras <= '1';
    wait;
end process;

p4 : process -- valid signal --
begin
    valid <= '1';
    wait for 1000 ms;
    valid <= '0';
    wait;
end process;

end behavioral;

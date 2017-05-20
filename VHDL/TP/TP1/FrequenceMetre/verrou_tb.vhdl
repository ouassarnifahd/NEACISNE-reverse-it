library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- Test Bench: verrou --

architecture behavioral of verrou_tb is

component verrou_tb is
    port ( clk : in STD_LOGIC;
           verr : in STD_LOGIC;
           freq : in STD_LOGIC_VECTOR(15 downto 0);
           freq_verr : out STD_LOGIC_VECTOR(15 downto 0));
end component verrou_tb;

signal clk : STD_LOGIC := '0';
signal verr : STD_LOGIC := '0';
signal freq : STD_LOGIC_VECTOR(15 downto 0) := X"0000";

signal freq_verr : STD_LOGIC_VECTOR(15 downto 0);

begin
    -- device under test --
    dut : verrou_tb PORT MAP(clk => clk, verr => verr, freq => freq, freq_verr => freq_verr);

p1 : process -- Horloge 100 MHz / 10ns --
begin
    clk <= '0';
    wait for 5 ns;
    clk <= '1';
    wait for 5 ns;
end process;

p2 : process -- verr signal --
begin
    verr <= '0';
    wait for 1000 ms;
    verr <= '1';
    wait for 1000 ms;
end process;

end behavioral;

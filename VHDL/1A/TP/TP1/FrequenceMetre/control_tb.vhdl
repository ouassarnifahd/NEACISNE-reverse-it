library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- Test Bench: control --

architecture behavioral of control_tb is

component control_tb is
    port ( clk : in STD_LOGIC;
           valid : out STD_LOGIC;
           raz : out STD_LOGIC;
           verr : out STD_LOGIC);
end component control_tb;

signal clk : STD_LOGIC := '0';

signal valid : STD_LOGIC;
signal raz : STD_LOGIC;
signal verr : STD_LOGIC;


begin
    -- device under test --
    dut : control_tb PORT MAP(clk => clk, valid => valid, raz => raz, verr => verr);

p1 : process -- Horloge 100 MHz / 10ns --
begin
    clk <= '0';
    wait for 5 ns;
    clk <= '1';
    wait for 5 ns;
end process;

end behavioral;
